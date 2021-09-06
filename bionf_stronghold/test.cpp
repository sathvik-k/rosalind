#include <iostream>
#include <fstream>

#include "BioLib.h"
#include "misc.h"

using namespace std;

// const string DNA_INPUT_FILE = "rosalind_dna.txt";
// const string RNA_INPUT_FILE = "rosalind_prot.txt";
const string DNA_INPUT_FILE = "small_dna.txt";
const string RNA_INPUT_FILE = "small_rna.txt";

void test_dna_stuff(DNA *dna)
{
    cout << "dna seq: " << dna->get_dna_seq() << endl;
    cout << "Count nucleotide frequencies:\n";

    unordered_map<char, int> freq_map = dna->count_nuc_freq();
    for (auto it = freq_map.begin(); it != freq_map.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "DNA to RNA transcription: " << dna->transcribe_to_rna_seq() << endl;
    cout << "Reverse complement: " << dna->reverse_complement() << endl;
}

void test_rna_stuff(RNA *rna)
{
    cout << "rna seq: " << rna->get_rna_seq() << endl;
    cout << "RNA to protein: " << rna->rna_to_protein() << endl;
}

void dna_setup(){
    // DNA stuff
    ifstream f_dna;
    f_dna.open(DNA_INPUT_FILE);
    string dna_in;
    f_dna >> dna_in;

    DNA *dna = new DNA(dna_in);
    f_dna.close();

    test_dna_stuff(dna);
    delete dna;
}

void rna_setup(){
    // RNA stuff
    ifstream f_rna;
    f_rna.open(RNA_INPUT_FILE);
    string rna_in;
    f_rna >> rna_in;

    RNA *rna = new RNA(rna_in);
    f_rna.close();

    test_rna_stuff(rna);
    delete rna;
}

void test_misc(){
    // misc problems
    int n = 28, k = 2;
    cout << "n = " << n << ", k = " << k << endl;
    // n-1 for 0-index
    cout << "num pairs: " << num_rabbit_pairs(n-1, k) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); // speeds up IO

    // BioLib *util = new BioLib();
    // delete util;
    test_misc();

    return 0;
}