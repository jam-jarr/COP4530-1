// Name: Huy Bui U82390903
// Name: Jamie Giarratana U81686143
// Description: Implementing a Doubly Linked List

#include <iostream>
#include <string>
#include "DNode.hpp"
#include "IntDList.hpp"
using namespace std;

/// Initialize a new Doubly Linked List
IntDList::IntDList()
{
    head = new DNode;
    tail = new DNode;
    head->next = tail;
    tail->prev = head;
}
IntDList::~IntDList()
{
    while (!isEmpty())
    {
        deleteFromHead();
    }
    delete head;
    delete tail;
}
/// Check if Linked List is empty
/// \return true if empty, false if not
bool IntDList::isEmpty() const
{
    return head->next == tail;
}
/// Add value to head of the Linked List
/// \param v value to be added
void IntDList::addToHead(int v)
{
    DNode *node = new DNode;
    node->val = v;
    DNode *temp = head->next;
    head->next = node;
    node->next = temp;
    temp->prev = node;
    node->prev = head;
}
/// Add value to tail of the Linked List
/// \param v value to be added
void IntDList::addToTail(int v)
{
    DNode *node = new DNode;
    node->val = v;
    DNode *temp = tail->prev;
    tail->prev = node;
    node->prev = temp;
    temp->next = node;
    node->next = tail;
}
/// Add value to the Linked List in order
/// \param v value to be added
void IntDList::insertInOrder(int v)
{
    DNode *curr = head->next;

    // Find the position where the new value should be inserted
    while (curr != tail && curr->val < v) {
        curr = curr->next;
    }

    // Create new node
    DNode *node = new DNode;
    node->val = v;

    // Insert the node before curr
    DNode* prev = curr->prev;
    prev->next = node;
    node->prev = prev;
    node->next = curr;
    curr->prev = node;
}
/// Remove value from head of the Linked List
/// \param v value to be removed
int IntDList::deleteFromHead()
{
    if (isEmpty())
    {
        throw length_error("Linked List is empty");
    }
    DNode *temp = head->next;
    int tempVal = temp->val;
    head->next = temp->next;
    temp->next->prev = head;
    delete temp;
    return tempVal;
}
/// Remove value from tail of the Linked List
/// \param v value to be removed
int IntDList::deleteFromTail()
{
    if (isEmpty())
    {
        throw length_error("Linked List is empty");
    }
    DNode *temp = tail->prev;
    int tempVal = temp->val;
    tail->prev = temp->prev;
    temp->prev->next = tail;
    delete temp;
    return tempVal;
}
/// Remove specific value from the Linked List
/// \param v value to be removed
void IntDList::deleteNode(int v)
{
    if (isEmpty())
    {
        throw length_error("Linked List is empty");
    }
    for (DNode *curr = head->next; curr != tail; curr = curr->next)
    {
        if (curr->val == v)
        {
            DNode *prev = curr->prev;
            DNode *next = curr->next;
            prev->next = next;
            next->prev = prev;
            delete curr;
            break;
        }
    }
}
/// Check if value is in Linked List
/// \param v value to be checked
bool IntDList::isInList(int v) const
{
    for (DNode *curr = head->next; curr != tail; curr = curr->next)
    {
        if (curr->val == v)
        {
            return true;
        }
    }
    return false;
}
/// Print all values in the Linked List
void IntDList::printAll() const
{
    for (DNode *curr = head->next; curr != tail; curr = curr->next)
    {
        cout << curr->val << " ";
    }
    cout << endl;
}
/// Add all values into a string
/// \return the string
string IntDList::addToString() const
{
    if (isEmpty())
    {
        return "";
    }
    string vals;
    for (DNode *curr = head->next; curr != tail; curr = curr->next)
    {
        vals += to_string(curr->val);
    }
    return vals;
}
