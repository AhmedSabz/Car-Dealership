//
// Created by Hemanth Karnati on 11/29/23.
//
#include "iostream"
#include "vector"
#include "vehicle.hpp"
#include "fstream"
#include "sstream"
#ifndef CMPE126LAB_FILEREADER_H
#define CMPE126LAB_FILEREADER_H

class FileReader
{
public:
    //PRE CONDITION: VECTOR MUST BE EMPTY
    //POST CONDITION: PARAMETERIZED VECTOR IS FILLED WITH VEHICLES
    void generateCarList(std::vector<Vehicle>& v1, const std::string& fileName);
};

void FileReader::generateCarList(std::vector<Vehicle> &v1, const std::string& fileName)
{
    std::ifstream inFile(fileName);
    if (!inFile.is_open())
    {
        std::cout << "There is an error in opening the file!" << std::endl;
        return;
    }
    std::string data;
    while (getline(inFile,data))
    {
        Vehicle temp;
        inFile >> temp;
        v1.push_back(temp);
    }
    inFile.close();
}

#endif //CMPE126LAB_FILEREADER_H
