#ifndef BIO_LIB_H_
#define BIO_LIB_H_

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

class DNA
{
public:
    DNA();
    DNA(const std::string &dna_in) : dna(dna_in)
    {
        // validate dna
        for (auto letter : dna)
        {
            if (letter != 'A' && letter != 'G' && letter != 'T' && letter != 'C')
                throw std::runtime_error("not a valid dna req");
        }
    }

    std::string get_dna_seq() { return this->dna; }

    // DNA - Counting DNA Nucleotides
    std::unordered_map<char, int> count_nuc_freq();

    // RNA - Transcribing DNA into RNA
    std::string transcribe_to_rna_seq();

    // REVC - Complementing a Strand of DNA
    std::string reverse_complement();

private:
    std::unordered_map<char, char> complement_map = {{'A', 'T'},
                                                     {'T', 'A'},
                                                     {'G', 'C'},
                                                     {'C', 'G'}};
    std::string dna;
};

class RNA
{
public:
    RNA();
    RNA(const std::string &rna_in) : rna(rna_in)
    {
        // validate rna
        for (auto letter : rna)
        {
            if (letter != 'A' && letter != 'G' && letter != 'U' && letter != 'C')
                throw std::runtime_error("not a valid dna req");
        }

        // read in codon table
        read_codon_table("codon_table.in");
    }

    void read_codon_table(std::string codon_filename)
    {
        std::ifstream f;
        f.open(codon_filename);
        std::string codon, protein;
        while (f >> codon >> protein)
        {
            if (protein == "Stop")
            {
                codon_table[codon] = '\0';
            }
            else
            {
                codon_table[codon] = protein[0];
            }
        }
    }

    std::string get_rna_seq() { return this->rna; }

    // PROT - Translating RNA to Protein
    std::string rna_to_protein();

private:
    std::unordered_map<std::string, char> codon_table;
    std::string rna;
};

class BioLib
{
public:
    BioLib() {}

private:
};

#endif
