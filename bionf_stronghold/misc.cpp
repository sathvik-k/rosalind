#include "misc.h"

#include <cstdint>
#include <stdexcept>
#include <numeric>
#include <iostream>

using namespace std;

// FIB - Rabbits and Recurrence Relations
// In 1202, Leonardo of Pisa (commonly known as Fibonacci) considered a mathematical exercise
// regarding the reproduction of a population of rabbits. He made the following simplifying
// assumptions about the population:
//  - The population begins in the first month with a pair of newborn rabbits.
//  - Rabbits reach reproductive age after one month.
//  - In any given month, every rabbit of reproductive age mates with another rabbit of reproductive age.
//  - Exactly one month after two rabbits mate, they produce one male and one female rabbit.
//  - Rabbits never die or stop reproducing.

// Given: Positive integers n ≤ 40 and k ≤ 5
// Return: The total number of rabbit pairs that will be present after n months,
// if we begin with 1 pair and in each generation, every pair of reproduction-age
// rabbits produces a litter of k rabbit pairs (instead of only 1 pair).
int num_rabbit_pairs(int n_months, int k_pairs)
{
    // largest n
    const int SIZE = 40;
    if (n_months > SIZE)
        throw runtime_error("error: n_months > 40");

    // compute recurrence relation -> bottom-up
    // start with 1, 1, 0, 0, ....
    static int gens[SIZE] = {1, 1};

    if (n_months == 0 || n_months == 1)
        return 1;

    // check if already computed
    if (gens[n_months] > 0)
        return gens[n_months];

    // total # rabbit pairs alive = # rabbits alive in previous month  + # offspring created
    // # offspring = # rabbits alive 2 months prior * k
    gens[n_months] = num_rabbit_pairs(n_months - 1, k_pairs) + (num_rabbit_pairs(n_months - 2, k_pairs) * k_pairs);

    return gens[n_months];
}
