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
        for it in range(0, 5):
            filePath = os.path.join(outputFolder, struct, f"in{sampleId}-{it}.perf")
            if not os.path.exists(filePath):
                print(f"File not found: {filePath}")
                continue
            
            content = open(filePath, "r").read().strip().split("\n")

            data.setdefault(struct, {}).setdefault(sampleId, {}).setdefault(it, {})
            data[struct][sampleId][it]["buildTime"] = int(content[0])
            data[struct][sampleId][it]["queryTime"] = int(content[1])
        data[struct][sampleId]["avgBuildTime"] = sum(data[struct][sampleId][it]["buildTime"] for it in range(0, 5)) / 5
        data[struct][sampleId]["avgQueryTime"] = sum(data[struct][sampleId][it]["queryTime"] for it in range(0, 5)) / 5

def createGraphs(sampleIds, subtitle):
    x = [i for i in range(len(sampleIds))]
    xticks = ["MS2", "Qbeta", "phiX174", "G4", "M13", "If1", "T7", "P22", "lambda", "T4", "E. coli"]

    plt.figure(figsize=(5, 6))
    plt.subplot(2, 1, 1)
    for struct in structs:
        y = [data[struct][sampleId]["avgBuildTime"] / 1000000 for sampleId in sampleIds]
        plt.plot(x, y, label=struct, marker='o', markersize=5, linewidth=2)

    plt.xticks(x, xticks, rotation=45)
    plt.ylabel("Tempo médio de construção (ms)")
    plt.title("Tempo médio de construção")
    plt.yscale("log")
    plt.legend()

    plt.subplot(2, 1, 2)
    for struct in structs:
        y = [data[struct][sampleId]["avgQueryTime"] / 1000000 for sampleId in sampleIds]
        plt.plot(x, y, label=struct, marker='o', markersize=5, linewidth=2)
    plt.xticks(x, xticks, rotation=45)
    plt.ylabel("Tempo médio de consulta (ms)")
    plt.title("Tempo médio de consulta")
    plt.yscale("log")
    plt.legend()

    plt.tight_layout()
    plt.savefig(os.path.join(pwd, f"graphs/{subtitle}.png"))

def main():
    samples = [sampleIds[i] for i in [6, 4, 1, 3, 2, 5, 9, 8, 10, 7, 0]]
    createGraphs(samples, "performance")

if __name__ == "__main__":
    main()
