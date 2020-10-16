#include <iostream>
#include <fstream>

#include "dna_lib.h"

using namespace std;

const string INPUT_FILE = "rosalind_prot.txt";
// const string INPUT_FILE = "small_rna.txt";

int main()
{
    ios_base::sync_with_stdio(false); // speeds up IO

    ifstream f;
    f.open(INPUT_FILE);

    string in;
    f >> in;

    dna_lib *util = new dna_lib(in);

    cout << "input: " << in << endl;

    // cout << "Count nucleotide frequencies:\n";
    // unordered_map<char, int> freq_map = util->count_nuc_freq(in);
    // for (auto it = freq_map.begin(); it != freq_map.end(); it++)
    // {
    //     cout << it->first << ": " << it->second << endl;
    // }

    // cout << "DNA to RNA transcription:\n";
    // cout << util->transcribe_to_rna(in) << endl;

    // cout << "Reverse complement: " << util->reverse_complement(in) << endl;

    cout << "RNA to protein: " << util->rna_to_protein(in) << endl;

    delete util;

    return 0;
}