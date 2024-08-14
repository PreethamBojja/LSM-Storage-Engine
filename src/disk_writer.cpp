#include "disk_writer.h"
#include <fstream>
#include <iostream>

void DiskWriter::write(const std::vector<std::string>& data) {
    std::ofstream outfile("output.txt", std::ios_base::app); // Append mode
    if (outfile.is_open()) {
        for (const auto& entry : data) {
            outfile << entry << std::endl;
        }
        outfile.close();
    } else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}
