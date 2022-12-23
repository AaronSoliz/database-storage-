
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) {
    this->books = 0;
    this->dice = 0;
    this->figures = 0;
    this->towers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { 
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { 
    return this->length;
}

CustomerDB::~CustomerDB(void) { 
    delete[] this->data;
}



void CustomerDB::clear(void) { 
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { 
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) {
    if(isMember(name)){
        int i = 0;
        while(i < this->length){
            if(this->data[i].name == name){
                return this->data[i];
            }
            i++;
        }
    }
    else{
        if(this->length >=  this->capacity){
            this->capacity *= 2;
            Customer* NewCustomerDatabase = new Customer[this->capacity];
            int j = 0;
            while(j < this->length){
                NewCustomerDatabase[j] = this->data[j];
                j++;
            }
            delete[] this->data;
            NewCustomerDatabase[length] = Customer(name);
            this->data = NewCustomerDatabase;
        }
        else{
            this->data[length] = Customer(name);
        }
        this->length++;
        return this->data[length - 1];
    }
}

bool CustomerDB::isMember(UTString name) {
    int i = 0;
    while(i< this->length){
        if(this->data[i].name == name){
            return true;
        }
        i++;
    }
    return false;
}

