#include "IntDList.h"
#include <iostream>
#include <limits>
using namespace std;
int nullValue = std::numeric_limits<int>::min(); // Smallest possible int

class DNode{
public:
    DNode();
private:
    int val;
    DNode* prev;
    DNode* next;
    friend class IntDList;
};
class IntDList {
public:
    IntDList();
    //return its value
    void addToHead(int);
    void insertInOrder (int);
    void addToTail(int);
    // delete the head and return its value;
    int deleteFromHead();
    // delete the tail and return its value;
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;
    //This method returns the string of the ordered integers
    string addToString() const;
private:
    bool isEmpty() const;
    DNode* head;
    DNode* tail;
};
/* TODO:
 * Node initialize constructor is wrong: head and tail must be nullptr
 * Function is empty is broken
 * Function insert inOrder is broken
 * All function is missing the check if the linked list is empty or not
 * Function addToString has not been implemented
 * Create a header file for the source file so that it could run unit test
 */
DNode::DNode(){
    val = nullValue;
    prev = nullptr;
    next = nullptr;
}

IntDList::IntDList(){
    head = new DNode;
    tail = new DNode;
    head->next = tail;
    tail->prev = head;
};
bool IntDList::isEmpty() const {
    if (head->next == tail){
        return true;
    } else return false;
}
void IntDList::addToHead(int v) {
    auto* node = new DNode;
    node->val = v;
    DNode* temp = head->next;
    head->next = node;
    node->next = temp;
    temp->prev = node;
    node->prev = head;
};

void IntDList::addToTail(int v) {
    auto* node = new DNode;
    node->val = v;
    DNode* temp = tail->prev;
    tail->prev = node;
    node->prev = temp;
    temp->next = node;
    node->next = tail;
}
void IntDList::insertInOrder(int v) {
    DNode* curr = head;
    for (; curr->next != nullptr && curr->val < v; curr = curr->next);
    auto* node = new DNode;
    DNode* prev = curr->prev;
    prev->next = node;
    node->next = curr;
    curr->prev = node;
    node->prev = prev;
}
int IntDList::deleteFromHead() {
    if (head->next->val == nullValue){
        return -1;
    }
    DNode* temp = head;
    int tempVal = temp->val;
    head = head->next;
    delete temp;
    return tempVal;
}
int IntDList::deleteFromTail() {
    if (tail->prev->val == nullValue){
        return -1;
    }
    DNode* temp = tail;
    int tempVal = temp->val;
    tail = tail->prev;
    delete temp;
    return tempVal;
}
void IntDList::deleteNode(int v) {
    for (DNode* curr = head->next; curr->next != nullptr; curr = curr->next){
        if (curr->val == v){
            DNode* temp = curr;
            DNode* prev = curr->prev;
            DNode* next = curr->next;
            prev->next = next;
            next->prev = prev;
            delete temp;
            break;
        }
    }
}

bool IntDList::isInList(int v) const {
    for (DNode* curr = head->next; curr->next != nullptr; curr = curr->next){
        if (curr->val == v){
            return true;
        }
    }
    return false;
}
void IntDList::printAll() const {
    for (DNode* curr = head->next; curr->next != nullptr; curr = curr->next){
        cout << curr->val << endl;
    }
}

int main(){
    IntDList myList;
    myList.insertInOrder(9);
    myList.insertInOrder(8);
    myList.insertInOrder(0);
    myList.insertInOrder(3);
    myList.printAll();
    return 0;
}