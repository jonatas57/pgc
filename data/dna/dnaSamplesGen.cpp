#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
  auto pwd = filesystem::current_path();

  string ecoli;
  ifstream coli("../E.coli");
  getline(coli, ecoli);
  vector<string> files;
  for (const auto& entry : filesystem::directory_iterator(pwd)) {
    if (entry.path().extension() == ".fasta") {
      ifstream file(entry.path());
      string s;
      getline(file, s);
      cerr << s << endl;
      string res;
      while (getline(file, s)) {
        res += s;
      }
      for (auto& c : res) c = tolower(c);
      files.push_back(res);
    }
  }
  sort(files.begin(), files.end(), [](const string& a, const string& b) {
    return a.size() < b.size();
  });

  // LCS
  int id = 28;
  for (auto& dna : files) {
    cerr << ("../4-lcs/samples/in" + to_string(id) + ".txt") << endl;
    ofstream out("../4-lcs/samples/in" + to_string(id++) + ".txt");
    out << ecoli << endl << dna << endl;
  }
  // frequencia
  id = 1;
  files.push_back(ecoli);
  for (auto& dna : files) {
    cerr << std::format("../6-frequenciaDNA/samples/in{:02d}.txt", id) << endl;
    ofstream out(std::format("../6-frequenciaDNA/samples/in{:02d}.txt", id++));
    out << dna << endl;
  }
  return 0;
}
