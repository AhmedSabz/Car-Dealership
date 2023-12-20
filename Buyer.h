//
// Created by Hemanth Karnati on 11/28/23.
//
#include "iostream"
#include "User.h"

#ifndef CMPE126LAB_BUYER_H
#define CMPE126LAB_BUYER_H

class Buyer: public User
{
private:
    int budget, num_cars;
public:
    friend std::ostream & operator << (std::ostream &out, const Buyer buyer);
    friend std::istream & operator >> (std::istream &in, Buyer &b);
    void buy(Vehicle v1)
    {
        if (this->budget < v1.getPrice())
        {
            std::cout << budget << endl;
            std::cout << "Insufficient funds u dumb brokie" << std::endl;
            return;
        }
        list_of_cars.push(v1);
        std::cout << "WOOHOO! YOU JUST BOUGHT:\n" << v1;
        this->budget -= v1.getPrice();
        num_cars--;
    }
    int getNumCars(){return num_cars;}
    void displayInfo() const override {
        std::cout << "The remaining budget for " << User::getName() << " is " << budget << "\nList of remaining cars: " << num_cars << std::endl;
    }


};

std::istream & operator >> (std::istream& in, Buyer& b)
{
    in >> static_cast<User&>(b);
    std::cout << "Enter in your budget: " << std::endl;
    in >> b.budget;
    std::cout << "Enter in the number of cars you want to buy: " << std::endl;
    in >> b.num_cars;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}

std::ostream  & operator << (std::ostream &out, const Buyer buyer)
{
    out << static_cast<const User&>(buyer);
    out << "\nBudget: " << buyer.budget
    << "\nNumber of interested cars: " << buyer.num_cars << std::endl;
    return out;
}

#endif //CMPE126LAB_BUYER_H
