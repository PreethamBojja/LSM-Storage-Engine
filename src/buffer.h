#ifndef BUFFER_H
#define BUFFER_H

#include <map>
#include <cstddef>
#include <vector>
#include <algorithm>
#include "murmur_hash.h"

using namespace std;

template<typename KeyType, typename ValueType>
class Buffer {
public:
    Buffer(size_t maxSize, size_t numLevels, size_t levelSize);
    ~Buffer();

    bool addData(const KeyType& key, const ValueType& value);
    bool isFull() const;
    void flushToDisk(); 
    void printBuffer() const; 

private:
    map<size_t, ValueType> entries;
    size_t maxSize;
    size_t numLevels;
    size_t levelSize;

    size_t hashKey(const KeyType& key) const;
    void sortEntries();
};

// Forward declarations for explicit instantiation
extern template class Buffer<int, string>;

#endif // BUFFER_H
