//
// Created by Hemanth Karnati on 11/28/23.
//

#include "iostream"
#include "vehicle.hpp"
#include "User.h"
#include "binaryTree.h"

#ifndef CMPE126LAB_SELLER_H
#define CMPE126LAB_SELLER_H

class Seller: public User
{
private:
    int profit, num_selling_cars;
public:
    int getNumCars(){return num_selling_cars;}
    friend std::ostream & operator << (std::ostream &out, const Seller seller);
    friend std::istream & operator >> (std::istream &in, Seller &b);
    void preloadCar(Vehicle &v1){
        list_of_cars.push(v1);
    }
    Vehicle sell()
    {
        Vehicle v1 = list_of_cars.top();
        list_of_cars.pop();
        profit += v1.getPrice();
        num_selling_cars--;
        return v1;
    }
    void displayInfo() const override{
        std::cout << "Total profit for " << User::getName() << ": " << profit << "\nRemaining cars to sell: " << num_selling_cars << std::endl;
    }
};

std::ostream & operator << (std::ostream &out, const Seller seller)
{
    out << "\nProfit Made: " << seller.profit << "\nSold Cars: " << seller.num_selling_cars
    << std::endl;
    return out;
}

std::istream & operator >> (std::istream &in, Seller &s1)
{
    in >> static_cast<User&>(s1);
    std::cout << "Enter how many cars you would want to sell: " << std::endl;
    in >> s1.num_selling_cars;
    s1.profit = 0;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}



#endif //CMPE126LAB_SELLER_H
