#include "disk_writer.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Template implementation
template <typename KeyType, typename ValueType>
void DiskWriter<KeyType, ValueType>::write(const map<KeyType, ValueType>& data) {
    ofstream outfile("output.txt", ios_base::app);  // Updated filename
    if (outfile.is_open()) {
        for (const auto& entry : data) {
            ostringstream keyStream, valueStream;
            keyStream << entry.first;
            valueStream << entry.second;

            outfile << keyStream.str() << ":" << valueStream.str() << endl;
        }
        outfile.close();
    } else {
        cerr << "Failed to open file for writing." << endl;
    }
}

// Explicit instantiation for specific types
template class DiskWriter<size_t, std::string>;
