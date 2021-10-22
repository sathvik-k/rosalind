#ifndef RNA_H_
#define RNA_H_

#include <string>
#include <unordered_map>

using namespace std;

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class RNA {
public:
  RNA() {}

  void validate_rna(string rna) {
    // validate rna
    assert(rna.length() % 3 == 0);
    for (auto letter : rna) {
      if (letter != 'A' && letter != 'G' && letter != 'U' && letter != 'C')
        throw runtime_error("not a valid rna seq");
    }

    // read in codon table
    read_codon_table("codon_table.in");
  }

  void read_codon_table(string codon_filename) {
    ifstream f;
    f.open(codon_filename);
    string codon, protein;
    while (f >> codon >> protein) {
      if (protein == "Stop") {
        codon_table[codon] = '\0';
      } else {
        codon_table[codon] = protein[0];
      }
    }
  }

  // PROT - Translating RNA to Protein
  string rna_to_protein(string rna);

private:
  unordered_map<string, char> codon_table;
};

#endif
