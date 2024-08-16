#include "disk_writer.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Template implementation
template <typename KeyType, typename ValueType>
void DiskWriter<KeyType, ValueType>::write(const std::unordered_map<KeyType, ValueType>& data) {
    std::ofstream outfile("output.txt", std::ios_base::app);  // Updated filename
    if (outfile.is_open()) {
        for (const auto& entry : data) {
            std::ostringstream keyStream, valueStream;
            keyStream << entry.first;
            valueStream << entry.second;

            outfile << keyStream.str() << ":" << valueStream.str() << std::endl;
        }
        outfile.close();
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}

// Explicit instantiation for specific types
template class DiskWriter<int, std::string>;
