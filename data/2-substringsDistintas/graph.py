import matplotlib.pyplot as plt
import os

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

            [buildTime, queryTime] = content

            data.setdefault(struct, {}).setdefault(sampleId, {}).setdefault(it, {})
            data[struct][sampleId][it]["buildTime"] = buildTime
            data[struct][sampleId][it]["queryTime"] = queryTime
        data[struct][sampleId]["avgBuildTime"] = sum(data[struct][sampleId][it]["buildTime"] for it in range(0, 10)) / 10
        data[struct][sampleId]["avgQueryTime"] = sum(data[struct][sampleId][it]["queryTime"] for it in range(0, 10)) / 10

def createGraphs(sampleIds, subtitle):
    x = sampleIds
    xticks = [rf"$10^{2 * (i + 1)}$" for i in range(len(sampleIds))]

    plt.figure(figsize=(5, 6))
    plt.subplot(2, 1, 1)
    for struct in structs:
        y = [data[struct][sampleId]["avgBuildTime"] / 1000000 for sampleId in sampleIds]
        plt.plot(x, y, label=struct, marker='o', markersize=5, linewidth=2)
    plt.xticks(x, xticks)
    plt.xlabel("Tamanho da string")
    plt.ylabel("Tempo médio de construção (ms)")
    plt.yscale("log")
    plt.title("Tempo médio de construção")
    plt.legend()

    plt.subplot(2, 1, 2)
    for struct in structs:
        y = [data[struct][sampleId]["avgQueryTime"] / 1000 for sampleId in sampleIds]
        print(struct, subtitle, y)
        plt.plot(sampleIds, y, label=struct, marker='o', markersize=5, linewidth=2)
    plt.xticks(sampleIds, xticks)
    plt.xlabel("Tamanho da string")
    plt.ylabel("Tempo médio de consulta (µs)")
    plt.title("Tempo médio de consulta")
    plt.yscale("log")
    plt.legend()
    plt.tight_layout()
    plt.savefig(os.path.join(pwd, f"graphs/{subtitle}.png"))

def main():
    createGraphs(sampleIds[0:5:2], "singleChar")
    createGraphs(sampleIds[5:10:2], "smallAlpha")
    createGraphs(sampleIds[10:15:2], "lowerCase")
    createGraphs(sampleIds[15:20:2], "ascii")

if __name__ == "__main__":
    main()
