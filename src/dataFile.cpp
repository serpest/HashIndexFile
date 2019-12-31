#include "dataFile.h"
#include "iostream"
DataFile::DataFile(std::string& filename) {
    stream.open(filename + ".dat" , std::ios::out | std::ios::in | std::ios::binary | std::ios::app);
}

DataFile::~DataFile() {
    stream.close();
}

long DataFile::search(Hashable& obj) {
    stream.seekg(0);
    Hashable* currentObj = &obj;
    long currentObjPos;
    while (!stream.eof()) {
        currentObjPos = stream.tellg();
        currentObj->read(stream);
        if (*currentObj == obj) {
            stream.clear();
            return currentObjPos;
        }
    }
    stream.clear();
    return -1;
}

long DataFile::append(Hashable& obj) {
    stream.seekp(0, std::ios::end);
    long pos = stream.tellp();
    obj.write(stream);
    return pos;
}

void DataFile::retrieve(Hashable& obj, long pos) {
    obj.readAt(stream, pos);
    stream.clear();
}