#ifndef MURMUR_HASH_H
#define MURMUR_HASH_H

#include <cstdint>

class MurmurHash {
public:
    static uint32_t hash32(const void* key, int len, uint32_t seed);
};

#endif // MURMUR_HASH_H
