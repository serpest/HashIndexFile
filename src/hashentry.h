#pragma once
#include "hashable.h"

class HashEntry {
    private:
        unsigned long hashKey;
        long posInDataFile;
    public:
        HashEntry(unsigned long hashKey01, long posInDataFile01) : hashKey(hashKey01), posInDataFile(posInDataFile01) {}
        std::ostream& write(std::ostream&) const;
        std::istream& read(std::istream&);
        unsigned long getHashKey() {return hashKey;}
        long getPosInDataFile() {return posInDataFile;}
        void setPosInDataFile(long posInDataFile01) {posInDataFile = posInDataFile01;}
};