#include "RNA.h"

// PROT - Translating RNA to Protein
string RNA::rna_to_protein(string rna) {
  this->validate_rna(rna);
  string protein = "";
  for (int start = 0; (start + 3) < rna.size(); start += 3) {
    string codon = rna.substr(start, 3);
    assert(codon_table.find(codon) != codon_table.end());
    if (codon_table[codon] != '\0') {
      protein += codon_table[codon];
    } else {
      break;
    }
  }

  return protein;
}