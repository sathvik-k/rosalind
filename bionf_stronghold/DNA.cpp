#include <algorithm>
#include <cassert>
#include <iostream>

#include "DNA.h"

using namespace std;

// DNA - Counting DNA Nucleotides
unordered_map<char, int> DNA::count_nuc_freq(string dna) {
  this->validate_dna(dna);
  unordered_map<char, int> m;
  for (auto nuc : dna) {
    if (m.find(nuc) == m.end()) {
      m[nuc] = 1;
    } else {
      m[nuc]++;
    }
  }

  return m;
}

// RNA - Transcribing DNA into RNA
string DNA::transcribe_to_rna_seq(string dna) {
  this->validate_dna(dna);
  string rna = "";
  for (auto nuc : dna) {
    if (dna[nuc] == 'T') {
      rna += 'U';
    } else {
      rna += nuc;
    }
  }

  return rna;
}

// REVC - Complementing a Strand of DNA
string DNA::reverse_complement(string dna) {
  this->validate_dna(dna);
  string comp = "";
  for (auto nuc : dna) {
    assert(this->complement_map.find(nuc) != this->complement_map.end());
    comp += this->complement_map[nuc];
  }
  reverse(comp.begin(), comp.end());
  return comp;
}

// GC - Computing GC Content
pair<string, double>
DNA::compute_gc_content(unordered_map<string, string> &fasta_map) {
  pair<string, double> res;
  double max_gc = -1;
  for (auto it = fasta_map.begin(); it != fasta_map.end(); it++) {
    double gc = 0;
    for (auto nuc : it->second) {
      if (nuc == 'G' || nuc == 'C')
        gc++;
    }
    double gc_cont = gc / it->second.size();
    if (gc_cont > max_gc) {
      max_gc = gc_cont;
      res.first = it->first;
      res.second = 100 * gc_cont;
    }
  }
  return res;
}

// HAMM - Counting Point Mutations
int DNA::hammingDistance(string dna1, string dna2) {
  assert(dna1.length() == dna2.length());
  int numPointMuts = 0;
  for (int i = 0; i < dna1.length(); i++) {
    if (dna1[i] != dna2[i])
      numPointMuts++;
  }
  return numPointMuts;
}

// SUBS - Finding a Motif in DNA