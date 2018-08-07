#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdint>

class HashTable {
public:

    HashTable()
        : table(26)
    {
    }

    void insert(const std::string& s) {
        // Generate HashID for the given key
        size_t id = this->genHash(s);

        // Insert into correct place in table
        table[id].push_back(s);
    }

    size_t genHash(const std::string& s) {
        size_t id = ((s[0] - 'A') % 26);
        return id;
    }









private:
    std::vector<std::list<std::string>> table;
};
