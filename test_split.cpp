/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    Node* head = new Node(0, nullptr);
    Node* evens = nullptr;
    Node* odds = nullptr;
    Node* temp = head;
    temp->next = new Node(0, nullptr);
    temp = temp->next;
    temp->next = new Node(0, nullptr);
    temp = temp->next;
    temp->next = new Node(0, nullptr);
    temp = temp->next;
    temp->next = new Node(0, nullptr);
    temp = temp->next;
    temp->next = new Node(0, nullptr);
    temp = temp->next;
    temp->next = new Node(0, nullptr);
    temp = nullptr;
    
    split(head, odds, evens);
    if (head != nullptr) {
        cout << "Error, \'in\' still has something!" << endl;
    } else {
        cout <<"Evens: ";
        while (evens != nullptr) {
            cout << evens->value << " ";
            temp = evens;
            evens = evens->next;
            delete temp;
        }
        cout << "End" << endl;
        cout <<"Odds: ";
        while (odds != nullptr) {
            cout << odds->value << " ";
            temp = odds;
            odds = odds->next;
            delete temp;
        }
        cout << "End" << endl;
    }
    return 0;
}
