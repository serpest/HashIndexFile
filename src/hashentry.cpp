#include "hashentry.h"

std::ostream& HashEntry::write(std::ostream& os) const {
    os.write((char*)&hashKey, sizeof(hashKey));
    os.write((char*)&posInDataFile, sizeof(posInDataFile));
    return os;
}

std::istream& HashEntry::read(std::istream& is) {
    is.read((char*)&hashKey, sizeof(hashKey));
    is.read((char*)&posInDataFile, sizeof(posInDataFile));
    return is;
}