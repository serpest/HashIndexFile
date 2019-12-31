#include "entriesfile.h"

EntriesFile::EntriesFile(std::string& filename) {
    stream.open(filename + ".index" , std::ios::out | std::ios::in | std::ios::binary);
    if (!stream)
        stream.open(filename + ".index" , std::ios::out | std::ios::in | std::ios::binary | std::ios::trunc);
}

EntriesFile::~EntriesFile() {
    stream.close();
}

void EntriesFile::insert(HashEntry& entry) {
    //Adaptation of the code copied from the book "A Complete Guide to Programming in C++".
    HashEntry currentEntry = entry;
    int size = sizeof(entry);
    stream.seekg(0, std::ios::end);
    long i = stream.tellg();
    i -= size;
    bool found = false;
    while(i >= 0 && !found) {
        stream.seekg(i);
        currentEntry.read(stream);
        if(entry.getHashKey() < currentEntry.getHashKey()) {
            stream.seekg(i + size);
            currentEntry.write(stream);
            i -= size;
        }
        else {
            found = true;
        }
    }
    stream.seekg(i + size);
    entry.write(stream);
}

bool EntriesFile::retrieve(HashEntry& entry) {
    //It goes faster if I implement the binary search algorithm.
    stream.seekg(0, std::ios::end);
    if (stream.tellg() == 0)
        return false;
    stream.seekg(0);
    HashEntry currentEntry(-1, -1);
    while (stream && !stream.eof()) {
        currentEntry.read(stream);
        if (currentEntry.getHashKey() == entry.getHashKey()) {
            entry.setPosInDataFile(currentEntry.getPosInDataFile());
            stream.clear();
            return true;
        }
    }
    stream.clear();
    return false;
}