#include <iostream>
#include "StackA.h"

using namespace std;

template <class DATA>
StackA<DATA>::StackA(int Max_Element)
{
    if (Max_Element < MIN_STACK_SIZE)
    {
        std::cout << "Sizs too Small" << std::endl;
        throw "Size too Small";
    }
    this->Array = new DATA[Max_Element];
    if (Array == nullptr)
    {
        throw "Out Of Space";
    }
    this->Capacity = Max_Element;
    this->MakeEmpty();
}

template <class DATA>
inline void StackA<DATA>::MakeEmpty()
{
    this->TopOfStack = EMPTY_TO_S;
}

template <class DATA>
inline bool StackA<DATA>::IsEmpty()
{
    return this->TopOfStack == EMPTY_TO_S;
}

template <class DATA>
inline bool StackA<DATA>::IsFull()
{
    return this->TopOfStack + 1 == this->Capacity;
}

template <class DATA>
inline bool StackA<DATA>::Push(DATA &elem)
{
    if (this->IsFull())
    {
        throw "Stack is Full";
        return false;
    }
    else
    {
        this->Array[++this->TopOfStack] = elem;
        return true;
    }
}

template<class DATA>
inline bool StackA<DATA>::Pop()
{
    if(this->IsEmpty())
    {
        throw "Stack is Empty";
    }
    else
    {
        this->TopOfStack--;
        return true;
    }
}

template<class DATA>
inline DATA StackA<DATA>::Top()
{
    if(!this->IsEmpty())
    {
        return this->Array[this->TopOfStack];
    }
    throw "Empty Stack";
    return 0;
}

template <class DATA>
StackA<DATA>::~StackA()
{
    if (this->Array != nullptr)
    {
        delete this->Array;
    }
}