#pragma once
#include <fstream>
#include "hashable.h"

class DataFile {
    private:
        std::fstream stream;
    public:
        DataFile(std::string&);
        ~DataFile();
        long search(Hashable&);
        long append(Hashable&);
        void retrieve(Hashable&, long);
};