import matplotlib.pyplot as plt
import os
from math import log10

pwd = os.path.dirname(os.path.abspath(__file__))

sampleFolder = os.path.join(pwd, "samples")
outputFolder = os.path.join(pwd, "output")

structs = ["array", "arvore", "automato"]

# sample file: in[id].txt
sampleIds = [f.split(".")[0][2:] for f in os.listdir(sampleFolder) if f.startswith("in") and f.endswith(".txt")]
sampleIds.sort()
sampleCount = len(sampleIds)

data = {}

for struct in structs:
    for sampleId in sampleIds:
        for it in range(0, 10):
            filePath = os.path.join(outputFolder, struct, f"in{sampleId}-{it}.perf")
            if not os.path.exists(filePath):
                print(f"File not found: {filePath}")
                continue
            
            content = list(map(float, open(filePath, "r").read().strip().split("\n")))

            buildTime = content[0]
            queryTimes = content[1:]

            data.setdefault(struct, {}).setdefault(sampleId, {}).setdefault(it, {})
            data[struct][sampleId][it]["buildTime"] = buildTime
            data[struct][sampleId][it]["queryTimes"] = queryTimes
            data[struct][sampleId][it]["avgQueryTime"] = sum(queryTimes) / len(queryTimes)
        data[struct][sampleId]["avgBuildTime"] = sum(data[struct][sampleId][it]["buildTime"] for it in range(0, 10)) / 10
        data[struct][sampleId]["avgQueryTime"] = sum(data[struct][sampleId][it]["avgQueryTime"] for it in range(0, 10)) / 10

def createGraphs(sampleIds, subtitle):
    x = [int(sampleId) for sampleId in sampleIds]
    xticks = [rf"$10^{i+4}$" for i in range(len(sampleIds))]

    plt.figure(figsize=(5, 6))
    plt.subplot(2, 1, 1)
    for struct in structs:
        y = [data[struct][sampleId]["avgBuildTime"] / 1000000 for sampleId in sampleIds]
        plt.plot(sampleIds, y, label=struct, marker='o', markersize=5, linewidth=2)
    plt.xticks(sampleIds, xticks)
    plt.xlabel("Tamanho da string")
    plt.ylabel("Tempo (ms)")
    plt.title("Tempo médio de construção")
    plt.yscale("log")
    plt.legend()

    plt.subplot(2, 1, 2)
    for struct in structs:
        y = [data[struct][sampleId]["avgQueryTime"] for sampleId in sampleIds]
        plt.plot(sampleIds, y, label=struct, marker='o', markersize=5, linewidth=2)
    plt.xticks(sampleIds, xticks)
    plt.xlabel("Tamanho da string")
    plt.ylabel("Tempo (ns)")
    plt.yscale("log")
    plt.title("Tempo médio de consulta")
    plt.legend()

    plt.tight_layout()
    plt.savefig(os.path.join(pwd, f"graphs/{subtitle}.png"))

def main():
    createGraphs(sampleIds[0:6:2], 'smallAlpha-smallPat')
    createGraphs(sampleIds[1:6:2], 'smallAlpha-largePat')
    createGraphs(sampleIds[6:12:2], 'lowerCase-smallPat')
    createGraphs(sampleIds[7:12:2], 'lowerCase-largePat')
    createGraphs(sampleIds[12:18:2], 'ascii-smallPat')
    createGraphs(sampleIds[13:18:2], 'ascii-largePat')

if __name__ == "__main__":
    main()
