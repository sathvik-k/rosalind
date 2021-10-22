#ifndef DNA_H_
#define DNA_H_

#include <string>
#include <unordered_map>

using namespace std;

class DNA {
public:
  DNA() {}

  void validate_dna(string dna) {
    for (auto letter : dna) {
      if (letter != 'A' && letter != 'G' && letter != 'T' && letter != 'C')
        throw std::runtime_error("not a valid dna seq");
    }
  }

  // DNA - Counting DNA Nucleotides
  unordered_map<char, int> count_nuc_freq(string dna);

  // RNA - Transcribing DNA into RNA
  string transcribe_to_rna_seq(string dna);

  // REVC - Complementing a Strand of DNA
  string reverse_complement(string dna);

  // GC - Computing GC Content
  pair<string, double>
  compute_gc_content(unordered_map<string, string> &fasta_map);

  // HAMM - Counting Point Mutations
  int hammingDistance(string dna1, string dna2);

private:
  unordered_map<char, char> complement_map = {
      {'A', 'T'}, {'T', 'A'}, {'G', 'C'}, {'C', 'G'}};
};

#endif
