#include "hashfile.h"

HashFile::HashFile(std::string filename01) : filename(filename01), dataFile(filename01), entriesFile(filename01) {}

void HashFile::insert(Hashable& obj) {
    HashEntry entry(obj.hash(), -1);
    if (entriesFile.retrieve(entry)) {
        return;
    }
    long pos = dataFile.append(obj);
    entry.setPosInDataFile(pos);
    entriesFile.insert(entry);
}

bool HashFile::retrieve(Hashable& obj, unsigned long hashKey) {
    HashEntry hashEntry(hashKey, -1);
    if (entriesFile.retrieve(hashEntry)) {
        dataFile.retrieve(obj, hashEntry.getPosInDataFile());
        return true;
    }
    return false;
}