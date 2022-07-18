#ifndef __STACK_H__
#define __STACK_H__

template <class DATA>
class Node
{
public:
    DATA Element;
    Node<DATA> *Next;

    Node();
    Node(DATA &value);
};

template <class DATA>
class Stack : public Node<DATA>
{
private:
    Node<DATA> *head;

public:
    Stack();
    bool IsEmpty();
    bool MakeEmpty();
    DATA Pop();
    bool Push(DATA &elem);
    DATA Top();
};

#endif