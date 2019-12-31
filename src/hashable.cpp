#include "hashable.h"

std::ostream& Hashable::writeAt(std::ostream& os, long pos) const {
    os.seekp(pos);
    return write(os);
}

std::istream& Hashable::readAt(std::istream& is, long pos) {
    is.seekg(pos);
    return read(is);
}