#ifndef DNA_LIB_H_
#define DNA_LIB_H_

#include <string>
#include <unordered_map>

class dna_lib
{
public:
    dna_lib();
    dna_lib(const std::string &in) : data(in) {}
    void set_data(const std::string &in) { data = in; }

    // DNA - Counting DNA Nucleotides
    std::unordered_map<char, int> count_nuc_freq(const std::string &dna_in);

    // RNA - Transcribing DNA into RNA
    std::string transcribe_to_rna(const std::string &dna_in);

    // REVC - Complementing a Strand of DNA
    std::string reverse_complement(const std::string &dna_in);

    // PROT - Translating RNA to Protein
    void read_codon_table();
    std::string rna_to_protein(const std::string &rna_in);

private:
    std::unordered_map<char, char> complement_map = {{'A', 'T'},
                                                     {'T', 'A'},
                                                     {'G', 'C'},
                                                     {'C', 'G'}};
    std::unordered_map<std::string, char> codon_table = {
        {"UUU", 'F'},
        {"CUU", 'L'},
        {"AUU", 'I'},
        {"GUU", 'V'},
        {"UUC", 'F'},
        {"CUC", 'L'},
        {"AUC", 'I'},
        {"GUC", 'V'},
        {"UUA", 'L'},
        {"CUA", 'L'},
        {"AUA", 'I'},
        {"GUA", 'V'},
        {"UUG", 'L'},
        {"CUG", 'L'},
        {"AUG", 'M'},
        {"GUG", 'V'},
        {"UCU", 'S'},
        {"CCU", 'P'},
        {"ACU", 'T'},
        {"GCU", 'A'},
        {"UCC", 'S'},
        {"CCC", 'P'},
        {"ACC", 'T'},
        {"GCC", 'A'},
        {"UCA", 'S'},
        {"CCA", 'P'},
        {"ACA", 'T'},
        {"GCA", 'A'},
        {"UCG", 'S'},
        {"CCG", 'P'},
        {"ACG", 'T'},
        {"GCG", 'A'},
        {"UAU", 'Y'},
        {"CAU", 'H'},
        {"AAU", 'N'},
        {"GAU", 'D'},
        {"UAC", 'Y'},
        {"CAC", 'H'},
        {"AAC", 'N'},
        {"GAC", 'D'},
        {"UAA", '\0'},
        {"CAA", 'Q'},
        {"AAA", 'K'},
        {"GAA", 'E'},
        {"UAG", '\0'},
        {"CAG", 'Q'},
        {"AAG", 'K'},
        {"GAG", 'E'},
        {"UGU", 'C'},
        {"CGU", 'R'},
        {"AGU", 'S'},
        {"GGU", 'G'},
        {"UGC", 'C'},
        {"CGC", 'R'},
        {"AGC", 'S'},
        {"GGC", 'G'},
        {"UGA", '\0'},
        {"CGA", 'R'},
        {"AGA", 'R'},
        {"GGA", 'G'},
        {"UGG", 'W'},
        {"CGG", 'R'},
        {"AGG", 'R'},
        {"GGG", 'G'},
    };
    std::string data;
};

#endif
