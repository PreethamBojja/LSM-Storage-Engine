#include "buffer.h"
#include <iostream>

int main() {
    Buffer buffer(5); // Buffer capacity of 5 entries

    for (int i = 0; i < 14; ++i) {
        buffer.addData("Data entry " + std::to_string(i));
    }
    buffer.printBuffer();
    return 0;
}
