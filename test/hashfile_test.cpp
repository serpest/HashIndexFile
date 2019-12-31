#include <iostream>
#include "hashfile.h"
#include "customer.h"
#define SIZE 8

using namespace std;

void createCustomers(Customer* customers[], unsigned long customersHashes[]) {
    cout << "Creating customers..." << endl;
    customers[0] = new Customer(0L, string("Emily"));
    customers[1] = new Customer(99L, string("Emma"));
    customers[2] = new Customer(42L, string("Arthur"));
    customers[3] = new Customer(7L, string("Daniel"));
    customers[4] = new Customer(89L, string("Joe"));
    customers[5] = new Customer(1024L, string("Perfect"));
    customers[6] = new Customer(1729L, string("serpest"));
    customers[7] = new Customer(12L, string("Mary"));
    cout << "Customers created." << endl;
    cout << "Creating customers' hashes array..." << endl;
    for (register int i = 0; i < SIZE; i++) {
        customersHashes[i] = customers[i]->hash();
    }
    cout << "Customers' hashes array created." << endl;
    cout << "List of the customers and their hashes:" << endl;
    for (register int i = 0; i < SIZE; i++) {
        cout << '\t' << customersHashes[i] << " -> ";
        customers[i]->display();
    }
}

void writeTest(Customer* customers[]) {
    cout << "Creating HashFile..." << endl;
    HashFile hashFile0(string("customers"));
    for (register int i = 0; i < SIZE; i++) {
        hashFile0.insert(*customers[i]);
    }
    cout << "HashFile created." << endl;
}

void readTest(unsigned long customersHashes[]) {
    cout << "Recreating array from the HashFile using hashes..." << endl;
    Customer recreatedCustomers[SIZE];
    HashFile hashFile1(string("customers"));
    for (register int i = 0; i < SIZE; i++) {
        hashFile1.retrieve(recreatedCustomers[i], customersHashes[i]);
    }
    cout << "Array recreated from the HashFile using hashes." << endl;
    cout << "List of the recreated customers and their hashes:" << endl;
    for (register int i = 0; i < SIZE; i++) {
        cout << '\t' << customersHashes[i] << " -> ";
        recreatedCustomers[i].display();
    }
}

int main() {
    Customer* customers[SIZE];
    unsigned long customersHashes[SIZE];
    cout << "CREATE CUSTOMERS:" << endl;
    createCustomers(customers, customersHashes);
    cout << "WRITE TEST:" << endl;
    writeTest(customers);
    cout << "READ TEST:" << endl;
    readTest(customersHashes);
    cout << "TEST FINISHED." << endl << "PRESS ENTER TO CONTINUE." << endl;
    cin.get();
    return 0;
}