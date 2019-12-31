#pragma once
#include <fstream>
#include "../src/dataFile.h"
#include "../src/entriesfile.h"

class HashFile {
    private:
        std::string filename;
        DataFile dataFile;
        EntriesFile entriesFile;
    public:
        HashFile(std::string);

        void insert(Hashable&);
        bool retrieve(Hashable&, unsigned long);
        //Hashable& operator[](int);
};