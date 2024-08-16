#ifndef DISK_WRITER_H
#define DISK_WRITER_H

#include <unordered_map>

template <typename KeyType, typename ValueType>
class DiskWriter {
public:
    void write(const std::unordered_map<KeyType, ValueType>& data);
};

// Explicit instantiation declarations (if needed)
extern template class DiskWriter<int, std::string>;

#endif // DISK_WRITER_H
