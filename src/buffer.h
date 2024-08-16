#ifndef BUFFER_H
#define BUFFER_H

#include <unordered_map>
#include <iostream>

using namespace std;

template<typename KeyType, typename ValueType>
class Buffer {
public:
    Buffer(size_t maxSize);
    ~Buffer();

    bool addData(const KeyType& key, const ValueType& value);
    bool isFull() const;
    void flushToDisk(); 
    void printBuffer() const; 

private:
    unordered_map<KeyType, ValueType> entries; 
    size_t maxSize;
};

// Forward declarations for explicit instantiation
extern template class Buffer<int, string>;

#endif // BUFFER_H
