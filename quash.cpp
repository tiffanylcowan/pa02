//Tiffany Cowan
//quash.cpp

#include "quash.h"
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

LinkedList::LinkedList():first(0){
}

LinkedList::~LinkedList(){
    Node *n = first;
    while(n!=0){
        Node *x = n->next;
        delete n;
        n = x;
    }
}

int LinkedList::append(int i){
    bool unique = 1;
    bool complete = 0;
    int result;
    
    if(first == NULL){ //linked list is empty
        first = new Node;
        first->number = i;
        first->count = 1;
        first->next = 0;
        result = 1;
    }
    else{ //not empty
        Node *n = first;
        if(n->number==i){ //if number is found in first
            n->count += 1; //increase count
            result = n->count;
            unique = 0;
        }
        else{ //look through rest of list to find it
            while(n->next){
                if(n->number==i){
                    n->count += 1;
                    result = n->count;
                    unique = 0;
                }
                n = n->next;
            }
        }
        if(unique){ //does not already exist
            Node *x = new Node;
            x->number = i;
            x->count = 1;
            x->next = 0;
            n->next = x;
            result = 1;
        }
    }
    return result;
}


int LinkedList::contains(int i){
    Node *n = first;
    while (n) {
        if (n->number == i)
            return n->count;
        n = n->next;
    }
    return 0;
}

int LinkedList::remove(int i){
    int result = -1;
    Node *n = first;
    if(first == NULL) //empty list
        return -1;
    if(n->number == i){ //number is found in first
        if(n->count > 1){ //more than one occurence
            n->count -= 1; //decrement count
            result = n->count;
        }
        else{ //only one occurence
            first = n->next; //update first
            delete n; //remove
            result = 0;
        }
    }
    else{ //not first
        while(n->next){
            if(n->next->number == i){
                if(n->next->count > 1){ //more than one occurence
                    n->next->count -= 1;
                    result = n->next->count;
                }
                else{ //one occurence
                    Node *x = n->next;
                    n->next = x->next;
                    delete x;
                    result = 0;
                }
            }
        }
        n = n->next;
    }
}
return result;
}


void insert(int i){
    int ct = arr[abs(i%43)].append(i);
    cout << "item successfully inserted, count = " + to_string(ct) << endl;
    if(ct == 1)
        m.push(i);
}

void lookup(int i){
    int ct = arr[abs(i%43)].contains(i);
    if(ct)
        cout << "item found, count = " + to_string(ct) << endl;
    else
        cout << "item not found" << endl;
}

void deletemin(){
    if(m.empty()){
        cout << "min item not present since table is empty" << endl;
    }
    else{
        int ct = arr[abs(m.top()%43)].remove(m.top());
        if(ct > 0){
            cout << "min item = " + to_string(m.top()) + ", count decremented, new count = " + to_string(ct) << endl;
        }
        else{
            cout << "min item " << to_string(m.top()) + " successfully deleted" << endl;
            m.pop();
        }
    }
}

void Delete(int i){
    int ct = arr[abs(i%43)].remove(i);
    if(ct > 0){
        cout << "item count decremented, new count = " + to_string(ct) << endl;
    }
    else if(ct == 0){
        cout << "item successfully deleted" << endl;
        m.remove(i);
    }
    else{
        cout << "item not present in the table" << endl;
    }
    return;
}

void print(){
    string out = "";
    minHeap mh(m); //copy of minHeap m
    while(mh.empty()!=1){ //not empty
        out += to_string(mh.top()) + " "; //add each term to output
        mh.pop(); //remove written terms
    }
    if(out.size())
        out.pop_back();
    cout << out << endl;
}

int ftoi(string str){
    int n = 0;
    if(str.find("insert") != string::npos) {
        n = 1;
    }
    else if(str.find("lookup") != string::npos) {
        n = 2;
    }
    else if(str.find("deleteMin") != string::npos) {
        n = 3;
    }
    else if((str.find("delete") != string::npos) and !(str.find("Min") != string::npos)) {
        n = 4;
    }
    else if(str.find("print") != string::npos) {
        n = 5;
    }
    return n;
}

int main(int argc, char** argv){
    //read in argument and execute respective functions as they are read
    stringstream ss;
    string temp;
    int number = 0;
    int function = 0;
    bool readInt = 0;
    int n = 0;
    
    while(!ss.eof()){
        ss >> temp;
        function = ftoi(temp);
        if(readInt or (function==3) or (function ==5)){ //deleteMin or print
            if(function == 3)
                n = 3;
            if(function == 5)
                n = 5;
            if(temp.back() == ',')
                temp.pop_back();
            else if(n == 1){
                insert(number);
            }
            else if(n == 2){
                lookup(number);
            }
            else if(n == 3){
                deletemin();
            }
            else if(n == 4){
                Delete(number);
            }
            else if(n == 5){
                print();
            }
            readInt = 0;
        }
        if((function == 1) or (function == 2) or (function == 4)){
            readInt = 1;
            n = function;
        }
        
        temp = "";
    }
    return 0;
}



