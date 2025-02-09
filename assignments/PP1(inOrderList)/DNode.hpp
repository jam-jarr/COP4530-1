//           Doubly-linked list class to store integers
#ifndef DNODE_H
#define DNODE_H
class DNode{
public:
    DNode();
private:
    int val;
    DNode* prev;
    DNode* next;
    friend class IntDList;
};
#endif /* DNODE_H */