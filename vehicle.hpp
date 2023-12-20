#ifndef CMPE126LAB_VEHICLE_H
#define CMPE126LAB_VEHICLE_H

#include <string>
#include <iostream>
using namespace std;

class Vehicle{
private:
    string brand;
    string model;
    float mpg;
    int price;
    string bodyType;
    string fuelType;
    

public:
    const string &getBrand() const;

    const string &getModel() const;

    float getMpg() const;

    int getPrice() const;

    const string &getBodyType() const;

    const string &getFuelType() const;

    bool operator <(const Vehicle &obj);
    bool operator >(const Vehicle &obj);
    bool operator ==(const Vehicle& obj);
    friend istream& operator>>(istream& in, Vehicle &obj);
    friend ostream & operator <<(ostream& out, const Vehicle obj);
    bool operator <=(const Vehicle &ob);
};

istream &operator >>(istream &in, Vehicle &obj) {
    in >> obj.brand >> obj.model >> obj.mpg >> obj.price >> obj.bodyType >> obj.fuelType;
//    std::getline(in,obj.brand,' ');
//    std::getline(in,obj.model,' ');
//    in >> obj.mpg >> obj.price;
//    std::getline(in,obj.bodyType,' ');
//    std::getline(in,obj.fuelType,' ');
    return in;
}

ostream &operator <<(ostream &out, const Vehicle obj) {
    out << obj.brand << " " << obj.model << " " << obj.mpg << " " << obj.price << " " << obj.bodyType << " "
    << obj.fuelType << endl;
    return out;
}

bool Vehicle::operator<(const Vehicle &obj) {
    return price < obj.price;
}

bool Vehicle::operator>(const Vehicle &obj) {
    return price > obj.price;
}

bool Vehicle::operator<=(const Vehicle &ob) {
    return brand <= ob.brand;
}

bool Vehicle::operator==(const Vehicle &obj)
{
    return price == obj.price;
}

const string &Vehicle::getBrand() const {
    return brand;
}

const string &Vehicle::getModel() const {
    return model;
}

float Vehicle::getMpg() const {
    return mpg;
}

int Vehicle::getPrice() const {
    return price;
}

const string &Vehicle::getBodyType() const {
    return bodyType;
}

const string &Vehicle::getFuelType() const {
    return fuelType;
}


#endif
