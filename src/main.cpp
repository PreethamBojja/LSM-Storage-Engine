#include "buffer.h"
#include "disk_writer.h"
#include <iostream>
#include <string>
#include <random>
#include <sstream>

using namespace std;

// Function to generate a random string of a given length
string generateRandomString(size_t length) {
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string result;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distrib(0, characters.size() - 1);
    
    for (size_t i = 0; i < length; ++i) {
        result += characters[distrib(generator)];
    }
    return result;
}

int main() {
    Buffer<int, string> buffer(5,10,3);
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> keyDistrib(1, 100);
    size_t numEntries = 13; 

    for (size_t i = 0; i < numEntries; ++i) {
        int key = keyDistrib(generator); // Generate a random key
        string value = generateRandomString(8); // Generate a random string of length 8
        buffer.addData(key, value);
    }

    buffer.printBuffer(); // Print buffer contents
    return 0;
}
