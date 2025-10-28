#include <stdint.h>

/*
These primes numbers are not constant but
standard in FNV-1a hash for 64-bit systems.
*/
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated)
static uint64_t hash(const char* key) {
    uint64_t hashed = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hashed ^= (uint64_t) (unsigned char) *p;
        hashed *= FNV_PRIME;
    }
    return hashed;
}