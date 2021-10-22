#include <fstream>
#include <iostream>
#include <unordered_map>

#include "DNA.h"

using namespace std;

extern unordered_map<string, string> read_fasta(string fasta_input_file);

const string DNA_INPUT_FILE = "rosalind_dna.txt";
// const string DNA_INPUT_FILE = "small_dna.txt";

void test_dna() {
  // DNA stuff
  ifstream f_dna;
  f_dna.open(DNA_INPUT_FILE);
  string dna_in;
  f_dna >> dna_in;

  DNA *dna = new DNA();
  f_dna.close();

  cout << "Count nucleotide frequencies:\n";
  unordered_map<char, int> freq_map = dna->count_nuc_freq(dna_in);
  for (auto it = freq_map.begin(); it != freq_map.end(); it++) {
    cout << it->first << ": " << it->second << endl;
  }

  cout << "DNA to RNA transcription: " << dna->transcribe_to_rna_seq(dna_in)
       << endl;
  cout << "Reverse complement: " << dna->reverse_complement(dna_in) << endl;

  delete dna;
}

unordered_map<string, string> read_fasta(string fasta_input_file) {
  unordered_map<string, string> fasta_map;

  ifstream fasta;
  fasta.open(fasta_input_file);

  string line, id, DNA_sequence;
  while (getline(fasta, line)) {
    if (line.empty())
      continue;
    // read fasta id and write to map
    if (line[0] == '>') {
      if (!id.empty())
        fasta_map[id] = DNA_sequence;
      id = line.substr(1);
      DNA_sequence.clear();
    } else {
      DNA_sequence += line;
    }
  }
  // last id
  if (!id.empty()) {
    fasta_map[id] = DNA_sequence;
  }

  fasta.close();

  return fasta_map;
}

void test_compute_gc_content() {
  unordered_map<string, string> fasta_map = read_fasta("fasta.txt");
  DNA *dna = new DNA();
  pair<string, double> gc_content = dna->compute_gc_content(fasta_map);
  cout << gc_content.first << endl << gc_content.second << endl;
  delete dna;
}

void test_hamming() {
  ifstream f_dna;
  f_dna.open("pointMutations.txt");
  string dna1, dna2;
  f_dna >> dna1;
  f_dna >> dna2;
  f_dna.close();
  DNA *dna = new DNA();
  cout << "hamming distance: " << endl;
  // cout << dna1 << endl << dna2 << endl;
  cout << dna->hammingDistance(dna1, dna2) << endl;
  delete dna;
}