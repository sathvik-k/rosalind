#include <cassert>
#include <iostream>
#include <algorithm>

#include "dna_lib.h"

using namespace std;

// DNA - Counting DNA Nucleotides
unordered_map<char, int> dna_lib::count_nuc_freq(const string &dna_in)
{
    unordered_map<char, int> m;
    for (auto nuc : dna_in)
    {
        if (m.find(nuc) == m.end())
        {
            m[nuc] = 1;
        }
        else
        {
            m[nuc]++;
        }
    }

    return m;
}

// RNA - Transcribing DNA into RNA
string dna_lib::transcribe_to_rna(const string &dna_in)
{
    string rna = "";
    for (auto nuc : dna_in)
    {
        if (dna_in[nuc] == 'T')
        {
            rna += 'U';
        }
        else
        {
            rna += dna_in[nuc];
        }
    }

    return rna;
}

// REVC - Complementing a Strand of DNA
string dna_lib::reverse_complement(const string &dna_in)
{
    string comp = "";
    for (auto nuc : dna_in)
    {
        assert(this->complement_map.find(nuc) != this->complement_map.end());
        comp += this->complement_map[nuc];
    }

    reverse(comp.begin(), comp.end());

    return comp;
}

// RNA to Protein
void dna_lib::read_codon_table()
{
}

string dna_lib::rna_to_protein(const std::string &rna_in)
{
    assert(rna_in.length() % 3 == 0);

    string protein = "";
    for (int start = 0; (start + 3) < rna_in.size(); start += 3)
    {
        string codon = rna_in.substr(start, 3);
        assert(codon_table.find(codon) != codon_table.end());
        if (codon_table[codon] != '\0')
        {
            protein += codon_table[codon];
        }
        else
        {
            break;
        }
    }
    return protein;
}