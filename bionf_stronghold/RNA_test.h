#include <fstream>
#include <iostream>
#include <unordered_map>

#include "RNA.h"

using namespace std;

// const string RNA_INPUT_FILE = "rosalind_prot.txt";
const string RNA_INPUT_FILE = "small_rna.txt";

void test_rna() {
  // RNA stuff
  ifstream f_rna;
  f_rna.open(RNA_INPUT_FILE);
  string rna_in;
  f_rna >> rna_in;

  RNA *rna = new RNA();
  cout << "RNA to protein: " << rna->rna_to_protein(rna_in) << endl;

  f_rna.close();

  delete rna;
}
