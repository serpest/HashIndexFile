#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "hashable.h"

class Customer : public Hashable {
    private:
        unsigned long id;
        char name[30];
    public:
        Customer(unsigned long = -1, std::string = "");
        unsigned long hash() const;
        std::ostream& write(std::ostream&) const;
        std::istream& read(std::istream&);
        void display() const;
        bool operator==(const Hashable&) const;
};