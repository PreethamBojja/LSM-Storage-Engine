#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <string>

class Buffer {
public:
    Buffer(size_t maxSize);
    ~Buffer();

    bool addData(const std::string& entry);
    bool isFull() const;
    void flushToDisk(); 
    void printBuffer() const; 

private:
    std::vector<std::string> entries; 
    size_t maxSize;
};

#endif // BUFFER_H
