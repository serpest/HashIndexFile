#include "customer.h"
#define HASH_RANGE 1024

Customer::Customer(unsigned long id01, std::string name01) : id(id01) {
    strncpy(name, name01.c_str(), sizeof(name) - 1);
    name[29] = '\0';
}

unsigned long Customer::hash() const {
    return id % HASH_RANGE;
}

std::ostream& Customer::write(std::ostream& os) const {
    os.write((char*)&id, sizeof(id));
    os.write(name, sizeof(name));
    return os;
}

std::istream& Customer::read(std::istream& is) {
    is.read((char*)&id, sizeof(id));
    is.read(name, sizeof(name));
    return is;
}

void Customer::display() const {
    std::cout << id << ": " << name << std::endl;
};

bool Customer::operator==(const Hashable& other) const {
    const Customer* otherCustomer = dynamic_cast<const Customer*>(&other);
    if (otherCustomer && id == otherCustomer->id && name == otherCustomer->name) {
        return true;
    }
    return false;
}