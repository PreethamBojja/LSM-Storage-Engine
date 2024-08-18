#include "buffer.h"
#include "disk_writer.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename KeyType, typename ValueType>
Buffer<KeyType, ValueType>::Buffer(size_t maxSize, size_t numLevels, size_t levelSize)
    : maxSize(maxSize), numLevels(numLevels), levelSize(levelSize) {}

template<typename KeyType, typename ValueType>
Buffer<KeyType, ValueType>::~Buffer() {
    // if (!entries.empty()) {
    //     flushToDisk();
    // }
}

template<typename KeyType, typename ValueType>
bool Buffer<KeyType, ValueType>::addData(const KeyType& key, const ValueType& value) {
    if (isFull()) {
        cout << "Buffer is full, flushing it to disk" << endl;
        flushToDisk();
    }
    size_t hashedKey = hashKey(key); // Hash the key
    entries[hashedKey] = value;
    return true;
}

template<typename KeyType, typename ValueType>
bool Buffer<KeyType, ValueType>::isFull() const {
    return entries.size() >= maxSize;
}

template<typename KeyType, typename ValueType>
void Buffer<KeyType, ValueType>::flushToDisk() {
    if (entries.empty()) {
        return;
    }

    sortEntries();
    DiskWriter<size_t, ValueType> writer;
    writer.write(entries);
    entries.clear(); // Clear the buffer after flushing
}

template<typename KeyType, typename ValueType>
void Buffer<KeyType, ValueType>::printBuffer() const {
    if (entries.empty()) {
        cout << "Buffer is empty." << endl;
        return;
    }
    cout << "----------------------------------------" << endl;
    cout << "| Hashed Key | Value                   |" << endl;
    cout << "----------------------------------------" << endl;

    for (const auto& entry : entries) {
        cout << "| " << setw(10) << entry.first << " | " << setw(30) << entry.second << " |" << endl;
    }

    cout << "----------------------------------------" << endl;
}

template<typename KeyType, typename ValueType>
void Buffer<KeyType, ValueType>::sortEntries() {
    vector<std::pair<size_t, ValueType>> sortedEntries(entries.begin(), entries.end());
    sort(sortedEntries.begin(), sortedEntries.end(),
              [](const pair<size_t, ValueType>& a, const pair<size_t, ValueType>& b) {
                  return a.first < b.first;
              });

    entries.clear();
    for (const auto& entry : sortedEntries) {
        entries[entry.first] = entry.second;
    }
}

template<typename KeyType, typename ValueType>
size_t Buffer<KeyType, ValueType>::hashKey(const KeyType& key) const {
    size_t hashedKey;
    hashedKey = MurmurHash::hash32(&key, sizeof(key), 0);
    return hashedKey;
}

// Explicit instantiation
template class Buffer<int, string>;
