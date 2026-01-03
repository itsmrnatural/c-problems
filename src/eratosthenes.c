/*
    Sieve of Eratosthenes is an algorithm for finding all the prime
    numbers in a segment  [1, n] using  O(n * loglogn) operations.

    Information:
    The number of primes ≤ n is roughly n / ln n (Prime Number Theorem, or PNT).
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// int naive(long, long*);
// int eratosthenes(long, long*);
// int euler(long);

int main(void) {
    return 0;
}

void populate(long* num, size_t size) {
    long i = 0;
    while (i < size) {
        num[i] = i + 2;
        i++;
    }
}

/*
    Implements a naive algorithm to find all primes up to 'num'.
    Checks each number for primality and stores found primes in the 'naived' array.
    Returns the count of primes found.
*/
long* naive(long num) {
    int prime_count = 0;
    long* numbers = (long*) malloc(sizeof(long) * (num - 1));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    populate(numbers, num - 1);
    for (int i = 2; i <= num; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            numbers[prime_count++] = i;
        }
    }

    return numbers;
}

/*
    Implements the Sieve of Eratosthenes algorithm to find all primes up to 'num'.
    Stores found primes in the 'sieved' array and returns the count of primes found.
*/
bool* eratosthenes(long num) {
    if (num < 2) return NULL;

    bool* primetable = (bool*) calloc(num, sizeof(bool));
    if (primetable == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < num; i++) {
        primetable[i] = true;
    }

    for (int i = 2; i * i <= num; i++) {
        if (primetable[i - 1] == false) continue;
        for (int j = i * i; j <= num; j += i) {
            primetable[j - 1] = false;
        }
    }
    return primetable;
}
