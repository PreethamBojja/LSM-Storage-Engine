#include "buffer.h"
#include "disk_writer.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Buffer<int, string> buffer(5); // Buffer with int keys and string values

    for (int i = 0; i < 12; ++i) {
        string value = "Value " + to_string(i);
        buffer.addData(i, value);
    }
    buffer.printBuffer();
    return 0;
}
