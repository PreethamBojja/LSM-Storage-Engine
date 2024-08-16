#include "buffer.h"
#include "disk_writer.h"
#include <iomanip>

using namespace std;

template<typename KeyType, typename ValueType>
Buffer<KeyType, ValueType>::Buffer(size_t maxSize) : maxSize(maxSize) {}

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
    entries[key] = value;
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

    DiskWriter<KeyType, ValueType> writer;
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
    cout << "| Key | Value                        |" << endl;
    cout << "----------------------------------------" << endl;

    for (const auto& entry : entries) {
        cout << "| " << setw(3) << entry.first << " | " << setw(30) << entry.second << " |" << endl;
    }

    cout << "----------------------------------------" << endl;
}

// Explicit instantiation
template class Buffer<int, string>;
