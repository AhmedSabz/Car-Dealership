//
// Created by Hemanth Karnati on 11/9/23.
//
#include <cstdlib> // For rand() and srand()
#include <ctime>
#include <iostream>
#include "User.h"
#include "Buyer.h"
#include "Seller.h"
#include "vector"
#include "stack"
#include "queue"
#include "vehicle.hpp"
#include "FileReader.h"
#include "binaryTree.h"
FileReader fileReader;
using namespace std;
    vector<Vehicle> v1; //TODO: Find someway to not hardcode this??

int findRight(std::vector<Vehicle>&v1)
{
    int x = 0;
    for(auto i = v1.begin(); i != v1.end(); ++i)
    {
        x++;
    }
    return x;
}

void merge(std::vector<Vehicle>& array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<Vehicle> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Vehicle>&v1, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left)/2;
        mergeSort(v1,left,mid);
        mergeSort(v1,mid+1,right);

        merge(v1,left,mid,right);
    }
}

void printVec(vector<Vehicle>&v1)
{
    for (int i = 0; i < v1.size(); i++) {
        std::cout << v1.at(i);
    }
    cout << endl;
}

Vehicle findVehicle(int price, vector<Vehicle>&v1)
{
    Vehicle temp;
    for (int i = 0; i < v1.size(); ++i) {
        if (v1.at(i).getPrice() == price) return v1.at(i);
    }
    cout << "There were no matching cars" << endl;
    return temp;
}

int main ()
{
    

    binaryTree car_list;
    fileReader.generateCarList(v1,"car_info_list.rtf");
    mergeSort(v1,0, findRight(v1)); //sorts cars by brand
    cout << "List of all our cars: \nBrand:  Model: MPG: Price: Body: Fuel:" << endl;
    printVec(v1);
    car_list.addData(v1);

    queue<User*>peopleInLine;
    Buyer Hemanth;
    Seller DLigs;
    cin>>Hemanth;
    peopleInLine.push(&Hemanth);
    cin>>DLigs;
    peopleInLine.push(&DLigs);

    cout << "\nLET US BEGIN THE AUCTION!!!" << endl;
    int sizeOfCarList = v1.size();

    while(!peopleInLine.empty()){
        User *temp=peopleInLine.front();
        peopleInLine.pop();

        Buyer* test = dynamic_cast<Buyer*>(temp);

        if(test ==nullptr){
            for(int i=0;i<  static_cast<Seller*>(temp)->getNumCars();i++){//choose a random car to be added to the vector
                int randomNumber = std::rand() % sizeOfCarList + 1;
                cout<<"preloading Car....";
                static_cast<Seller*>(temp)->preloadCar(v1.at(randomNumber)); //preloads cars that seller has and sells those cars
            }
            cout<<"selling "<<static_cast<Seller*>(temp)->sell();

        }else {
            int minPrice,maxPrice;
            vector<Vehicle> carsAffordable;
            do {
                cout << "Enter your min and max price, hit enter after each value " << temp->getName() << ": " << endl;
                cin >> minPrice >> maxPrice;
                carsAffordable = car_list.getCars(minPrice,maxPrice);
            } while (carsAffordable.empty());
            cout << "Here are your list of cars: \n";
            printVec(carsAffordable);
            cout << "Enter the price of the car that you want: " << endl;
            int price;
            cin >> price;
            static_cast<Buyer*>(temp)->buy(findVehicle(price,carsAffordable));
        }
        temp->displayInfo();
    }
    return 0;
}



