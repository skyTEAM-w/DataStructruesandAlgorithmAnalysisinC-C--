#include <iostream>
#include "Stack.h"

/**
 * @brief Construct a new Node< D A T A>:: Node object
 *
 * @tparam DATA ElementType
 */
template <class DATA>
inline Node<DATA>::Node()
{
    this->Next = nullptr;
}

/**
 * @brief Construct a new Node< D A T A>:: Node object
 *
 * @tparam DATA ElementType
 * @param value Real value of Node
 */
template <class DATA>
inline Node<DATA>::Node(DATA &value)
{
    this->value = value;
    this->Next = nullptr;
}

template <class DATA>
inline Stack<DATA>::Stack()
{
    this->head = new Node<DATA>();
    if (this->head == nullptr)
    {
        std::cout << "Error allocate memoryies" << std::endl;
    }
    this->head->Next = nullptr;
}

template <class DATA>
inline bool Stack<DATA>::IsEmpty()
{
    return this->head->Next == nullptr;
}

template <class DATA>
inline bool Stack<DATA>::MakeEmpty()
{
    if (this->head == nullptr)
    {
        std::cout << "No Stack Exsist" << std::endl;
    }
    else
        while (!this->IsEmpty())
        {
            this->Pop();
        }
}

template <class DATA>
inline bool Stack<DATA>::Push(DATA &elem)
{
    Node<DATA> *newnode = new Node<>(elem);
    if (newnode == nullptr)
    {
        std::cout << "Out of space" << std::endl;
        return false;
    }
    else
    {
        newnode->Next = this->head->Next;
        this->head->Next = newnode;
        return true;
    }
}

template <class DATA>
inline DATA Stack<DATA>::Pop()
{
    Node<DATA> *top;
    if (this->IsEmpty())
    {
        std::cout << "Empty Stack" << std::endl;
        return NULL;
    }
    else
    {
        DATA temp = this->head->Next->Element;
        top = this->head->Next;
        this->head->Next = this->head->Next->Next;
        free(top);
        return temp;
    }
}

template <class DATA>
inline DATA Stack<DATA>::Top()
{
    if (!this->IsEmpty())
    {
        return this->head->Next->Element;
    }
    std::cout << "Empty Stack" << std::endl;
    return NULL;
}