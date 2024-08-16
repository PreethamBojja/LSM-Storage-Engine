#ifndef DISK_WRITER_H
#define DISK_WRITER_H

#include <map>

template <typename KeyType, typename ValueType>
class DiskWriter {
public:
    void write(const std::map<KeyType, ValueType>& data);
};

// Explicit instantiation declarations (if needed)
extern template class DiskWriter<int, std::string>;

#endif // DISK_WRITER_H
