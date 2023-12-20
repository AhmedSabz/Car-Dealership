//
// Created by Hemanth Karnati on 11/28/23.
//

#include "iostream"
#include "stack"
#include "vehicle.hpp"


#ifndef CMPE126LAB_USER_H
#define CMPE126LAB_USER_H

class User
{
private:
    std::string name, email, address, phone_number;
protected:
    std::stack<Vehicle> list_of_cars;

public:
    friend std::ostream & operator << (std::ostream &out, const User buyer);
    friend std::istream & operator >> (std::istream &in, User &b);

    std::string getName() const {return name;}
    std::string getAddress(){return address;}
    std::string getEmail(){return email;}
    std::string getNumber(){return phone_number;}

    virtual void displayInfo() const
    {
        std::cout << "Name: " << name <<
            "\nHome Address: " << address <<
            "\nEmail Address: " << email <<
            "\nPhone #: " << phone_number << std::endl;
    }

};

std::ostream & operator << (std::ostream &out, const User buyer)
{
    out << "Name: " << buyer.name <<
    "\nHome Address: " << buyer.address <<
    "\nEmail Address: " << buyer.email <<
    "\nPhone #: " << buyer.phone_number;
    return out;
}

std::istream & operator >> (std::istream &in, User &b)
{

    std::cout << "Enter your name: \n";
    getline(in,b.name);
    std::cout << "Enter your email: \n";
    getline(in,b.email);

    std::cout << "Enter your home address: \n";
    getline(in,b.address);
    std::cout << "Enter your phone number (just sequence of numbers): \n";
    getline(in,b.phone_number);
    return in;
}



#endif //CMPE126LAB_USER_H
