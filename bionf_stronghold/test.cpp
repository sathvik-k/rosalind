#include <fstream>
#include <iostream>
#include <unordered_map>

#include "BioLib.h"
#include "DNA_test.h"
#include "RNA_test.h"
#include "misc.h"

using namespace std;

void test_misc() {
  // misc problems
  int n = 28, k = 2;
  cout << "n = " << n << ", k = " << k << endl;
  // n-1 for 0-index
  cout << "num pairs: " << num_rabbit_pairs(n - 1, k) << endl;
}

int main() {
  ios_base::sync_with_stdio(false); // speeds up IO

  //   BioLib *util = new BioLib();
  //   delete util;
  //   test_misc();
  //   test_rna();
  //   test_dna();
  //   test_compute_gc_content();
  test_hamming();

  return 0;
}