#include "buffer.h"
#include <iostream>
#include <iomanip>
#include "disk_writer.h"

using namespace std;

Buffer::Buffer(size_t maxSize) : maxSize(maxSize) {}

Buffer::~Buffer() {
    // if (!entries.empty()) {
    //     flushToDisk();
    // }
}

bool Buffer::addData(const std::string& entry) {
    if (isFull()) {
        cout << "Buffer is full, flushing it to disk" << endl;
        flushToDisk();
        entries.push_back(entry);
        return true;
    }
    entries.push_back(entry);
    return false;
}

bool Buffer::isFull() const {
    return entries.size() >= maxSize;
}

void Buffer::flushToDisk() {
    if (entries.empty()) {
        return;
    }

    DiskWriter writer;
    writer.write(entries);
    entries.clear(); // Clear the buffer after flushing
}

void Buffer::printBuffer() const {
    if (entries.empty()) {
        cout << "Buffer is empty." << endl;
        return;
    }
    cout << "----------------------------------------" << endl;
    cout << "| Index | Data Entry                     |" << endl;
    cout << "----------------------------------------" << endl;

    int index = 0;
    for (const auto& entry : entries) {
        cout << "| " << setw(5) << index++ << " | " 
             << setw(30) << left << entry << " |" << endl;
    }

    cout << "----------------------------------------" << endl;
}
