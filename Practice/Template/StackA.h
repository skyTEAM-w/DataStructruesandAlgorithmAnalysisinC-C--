#include <iostream>
#ifndef __STACKA_H__
#define __STACKA_H__

#define EMPTY_TO_S (-1)
#define MIN_STACK_SIZE (5)

template <class DATA>
class StackA
{
private:
    int Capacity;
    int TopOfStack;

public:
    DATA *Array;

    StackA(int Max_Element);
    ~StackA();

    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    bool Push(DATA &elem);
    bool Pop();

    DATA Top();
};

#endif