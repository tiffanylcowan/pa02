//quash.h

#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#ifndef QUASH_H
#define QUASH_H



struct Node{
    int number; //value
    int count; //how many times we see the value
    Node *next; //points to next element
};

class LinkedList{
public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor
    Node *first;
    int append(int i); //inserts i into linkedlist, returns count
    int contains(int i); //checks if linkedlist already contains i, returns count
    int remove(int i); //removes i from linkedlist, returns count
};

LinkedList arr[43]; //initialize size 43

class minHeap: public priority_queue<int, vector<int>, greater<int>> { //<type, vector<type>, comparisontype>
    
public:  bool remove(const int& number){
    auto it = std::find(this->c.begin(), this->c.end(), number);
    if(it != this->c.end()){
        this->c.erase(it);
        std::make_heap(this->c.begin(), this->c.end(), this->comp);
        return true;
    }
    else
        return false;
}
    
};


minHeap m; //initialize minheap
//functions for minheap
void insert(int i);
void lookup(int i);
void deletemin();
void Delete(int i);
void print();
int ftoi(); //turns function into integer to determine which function to call

#endif



