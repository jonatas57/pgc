import matplotlib.pyplot as plt
import os

pwd = os.path.dirname(os.path.abspath(__file__))

sampleFolder = os.path.join(pwd, "samples")
outputFolder = os.path.join(pwd, "output")

structs = ["array", "arvore", "automato"]

sampleIds = [f.split(".")[0][2:] for f in os.listdir(sampleFolder) if f.startswith("in") and f.endswith(".txt")]
sampleIds.sort()
sampleCount = len(sampleIds)

data = {struct: {} for struct in structs}

for struct in structs:
    for sampleId in sampleIds:
        for it in range(0, 10):
            filePath = os.path.join(outputFolder, struct, f"in{sampleId}-{it}.perf")
            if not os.path.exists(filePath):
                print(f"File not found: {filePath}")
                continue
            
            content = open(filePath, "r").read().strip().split("\n")
            buildTime = float(content[0])
            
            data[struct].setdefault(sampleId, {}).setdefault(it, {})
            data[struct][sampleId][it]["buildTime"] = buildTime
            data[struct][sampleId][it]["queryTimes"] = [float(x) for x in content[1:]]

        data[struct][sampleId]["avgBuildTime"] = sum(data[struct][sampleId][it]["buildTime"] for it in range(0, 10)) / 10
        data[struct][sampleId]["avgQueryTimes"] = [sum(data[struct][sampleId][it]["queryTimes"][q] for it in range(0, 10)) / 10 for q in range(len(data[struct][sampleId][0]["queryTimes"]))]

def createGraphs(sampleIds, subtitle):
    x = [int(sampleId) for sampleId in sampleIds]
    xticks = [rf"$10^{2 * (i + 1)}$" for i in range(len(sampleIds))]
    plt.figure(figsize=(5, 6))
    plt.subplot(2, 1, 1)
    for struct in structs:
        y = [data[struct][sampleId]["avgBuildTime"] / 1000000 for sampleId in sampleIds]
        plt.plot(x, y, label=struct, marker='o', markersize=5, linewidth=2)
    plt.xticks(x, xticks)
    plt.xlabel("Tamanho da string")
    plt.ylabel("Tempo médio de construção (ms)")
    plt.title("Tempo médio de construção")
    plt.yscale("log")
    plt.legend()

    plt.subplot(2, 1, 2)
    for struct in structs:
        y = [sum(data[struct][sampleId]["avgQueryTimes"]) / len(data[struct][sampleId]["avgQueryTimes"]) / 1000 for sampleId in sampleIds]
        plt.plot(x, y, label=struct, marker='o', markersize=5, linewidth=2)
    plt.xticks(x, xticks)
    plt.xlabel("Tamanho da string")
    plt.ylabel("Tempo médio de consulta (µs)")
    plt.yscale("log")
    plt.title("Tempo médio de consulta")
    plt.legend()

    plt.tight_layout()
    plt.savefig(os.path.join(pwd, f"graphs/{subtitle}.png"))

def main():
    createGraphs(sampleIds[0:3], "smallAlpha")
    createGraphs(sampleIds[3:6], "lowerCase")
    createGraphs(sampleIds[6:9], "ascii")

if __name__ == "__main__":
    main()
