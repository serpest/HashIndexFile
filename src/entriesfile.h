#pragma once
#include <fstream>
#include "hashentry.h"

class EntriesFile {
    private:
        std::fstream stream;
    public:
        EntriesFile(std::string&);
        ~EntriesFile();
        void insert(HashEntry&);
        bool retrieve(HashEntry&);   
};