
#ifndef binarytree_h
#define binarytree_h
#include <iostream>
#include "vehicle.hpp"
#include "vector"
using namespace std;


struct binaryTreeNode {
    Vehicle info;
    binaryTreeNode *lLink;
    binaryTreeNode *rLink;
    
    binaryTreeNode() {
        info;
        lLink = nullptr;
        rLink = nullptr;
    }

    binaryTreeNode(Vehicle item) {
        info = item;
        lLink = nullptr;
        rLink = nullptr;
    }
};


class binaryTree {
private:
    binaryTreeNode*root;
    
    void insertItem(binaryTreeNode *&obj, Vehicle item);
    binaryTreeNode* deleteItem(binaryTreeNode *&obj, Vehicle item);
    int nodeCounter(binaryTreeNode *&obj);
    int leafCounter(binaryTreeNode *&obj);
    void printPre(binaryTreeNode *&obj);
    void printIn(binaryTreeNode *&obj, int min, int max, vector<Vehicle>& group);
    vector<Vehicle> getList(binaryTreeNode* r, int min, int max) {
        std::vector<Vehicle> cars;
        printIn(r,min,max,cars);
        return cars;
    }

public:

    vector<Vehicle> getCars(int minPrice, int maxPrice)
    {
        return getList(root,minPrice,maxPrice);
    }

    
    binaryTree() {
        root = nullptr;
    }
    
    void insert(Vehicle item) {
        insertItem(root, item);
    }
    
    int nodeCount() {
        return nodeCounter(root);
    }
    
    int leafCount() {
        return leafCounter(root);
    }
    
    void deleter(Vehicle item) {
        deleteItem(root, item);
    }
    
    void preOrder() {
        cout << "Binary Tree in Preorder: ";
        printPre(root);
        cout << endl;
    }

    void addData(std::vector<Vehicle> list) {
        for (auto i = list.begin(); i < list.end(); ++i) {
            insert(*i);
        }
    }


    
};

void binaryTree::printIn(binaryTreeNode *&obj, int min, int max, vector<Vehicle>& group)
{
    if(obj != nullptr)
    {
        printIn(obj->lLink,min,max,group);
        if(obj->info.getPrice() > min &&  obj->info.getPrice() < max) group.push_back(obj->info);
        printIn(obj->rLink,min,max,group);
    }
}



void binaryTree::insertItem(binaryTreeNode *&obj, Vehicle item) {
    if(obj == nullptr) {
        obj = new binaryTreeNode(item);
    }
    else if(item < obj->info) {
        insertItem(obj->lLink, item);
    }
    else if(item > obj->info) {
        insertItem(obj->rLink, item);
    }
}


binaryTreeNode* binaryTree::deleteItem(binaryTreeNode*&obj, Vehicle item) {
    if(obj == nullptr) {
        return obj;
    }
    else if(item < obj->info) {
        obj->lLink = deleteItem(obj->lLink, item);
    }
    else if(item > obj->info) {
        obj->rLink = deleteItem(obj->rLink, item);
    }
    else if(item == obj->info) {
        if(obj->lLink == nullptr) {
            binaryTreeNode *temp = obj->rLink;
            delete obj;
            return temp;
        }
        else if(obj->rLink == nullptr) {
            binaryTreeNode *temp = obj->lLink;
            delete obj;
            return temp;
        }
        
    }
    return obj;
}
vector<Vehicle> findMaxPrice(int lower, int upper){
    vector<Vehicle>a;
    
}

int binaryTree::nodeCounter(binaryTreeNode *&obj) {
    if(obj == nullptr) {
        return 0;
    }
    else {
        return 1 + nodeCounter(obj->lLink) + nodeCounter(obj->rLink);
    }
}


int binaryTree::leafCounter(binaryTreeNode *&obj) {
    if(obj == nullptr) {
        return 0;
    }
    else if(obj->lLink == nullptr && obj->rLink == nullptr) {
        return 1;
    }
    return leafCounter(obj->lLink) + leafCounter(obj->rLink);
}


void binaryTree::printPre(binaryTreeNode *&obj) {
    if(obj != nullptr) {
        cout << obj->info << " ";
        printPre(obj->lLink);
        printPre(obj->rLink);
    }
}


#endif /* binarytree_h */
