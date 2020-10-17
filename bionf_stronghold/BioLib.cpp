#include <cassert>
#include <iostream>
#include <algorithm>

#include "BioLib.h"

using namespace std;

// DNA - Counting DNA Nucleotides
unordered_map<char, int> DNA::count_nuc_freq()
{
    unordered_map<char, int> m;
    for (auto nuc : this->dna)
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
string DNA::transcribe_to_rna_seq()
{
    string rna = "";
    for (auto nuc : this->dna)
    {
        if (this->dna[nuc] == 'T')
        {
            rna += 'U';
        }
        else
        {
            rna += nuc;
        }
    }

    return rna;
}

// REVC - Complementing a Strand of DNA
string DNA::reverse_complement()
{
    string comp = "";
    for (auto nuc : this->dna)
    {
        assert(this->complement_map.find(nuc) != this->complement_map.end());
        comp += this->complement_map[nuc];
    }

    reverse(comp.begin(), comp.end());

    return comp;
}

// PROT - Translating RNA to Protein
string RNA::rna_to_protein()
{
    assert(this->rna.length() % 3 == 0);

    string protein = "";
    for (int start = 0; (start + 3) < this->rna.size(); start += 3)
    {
        string codon = this->rna.substr(start, 3);
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