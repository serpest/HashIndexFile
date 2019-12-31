#pragma once
#include <ostream>
#include <istream>

class Hashable {
    public:
        Hashable() {}
        virtual ~Hashable() {}
        std::ostream& writeAt(std::ostream&, long) const;
        std::istream& readAt(std::istream&, long);
        virtual unsigned long hash() const = 0;
        virtual std::ostream& write(std::ostream&) const = 0;
        virtual std::istream& read(std::istream&) = 0;
        virtual bool operator==(const Hashable&) const = 0;
};