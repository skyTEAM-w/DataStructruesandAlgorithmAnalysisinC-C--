#include <iostream>
#include "LinkedList.hpp"

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

/**
 * @brief Construct a new Linked List< D A T A>:: Linked List object
 *
 * @tparam DATA ElementType
 */
template <class DATA>
inline LinkedList<DATA>::LinkedList()
{
    this->head == (Node<DATA> *)malloc(sizeof(Node<DATA>));
    if (this->head == nullptr)
    {
        std::count << "Error: allocating memories FAILED" << std::endl;
    }
    this->head->Next == nullptr;
}

/**
 * @brief LinkedList Empty Judgement
 *
 * @tparam DATA ElementType
 * @return true 'empty'
 * @return false 'not empty'
 */
template <class DATA>
inline bool LinkedList<DATA>::IsEmpty()
{
    if (this->head == nullptr)
        return true;
    else
        return false;
}

/**
 * @brief Last Node Judgement
 *
 * @tparam DATA ElementType
 * @param Position position of node
 * @return true 'Last'
 * @return false 'not Last'
 */
template <class DATA>
inline bool LinkedList<DATA>::IsLast(Node<DATA> *Position)
{
    if (Position->Next == nullptr)
        return true;
    else
        return false
}

/**
 * @brief get the length of LinkedList
 *
 * @tparam DATA ElementType
 * @return int the length of LinkedList
 */
template <class DATA>
inline int LinkedList<DATA>::GetLen()
{
    int counter = 0;
    Node<DATA> *temp = this->head->Next;
    while (temp)
    {
        counter++;
        temp = temp->Next;
    }
    return counter;
}

/**
 * @brief Insert a new node in the first place of LinkedList
 *
 * @tparam DATA ElementType
 * @param value Node's value
 */
template <class DATA>
void LinkedList<DATA>::Insert(DATA &value)
{
    Node<DATA> *newnode = new Node<DATA>(value);
    newnode->Next = this->head->Next;
    this->head->Next = newnode;
}

/**
 * @brief Insert a new node in the certern place(index)
 *
 * @tparam DATA ElementType
 * @param value Node's value
 * @param index insert place
 * @return true 'Insert Sucessful'
 * @return false 'Insert Failed'
 */
template <class DATA>
bool LinkedList<DATA>::Insert(DATA &value, int index)
{
    if (index <= 0 || index > this->GetLen())
    {
        std::cout << "Insert Position ERROR" << std::endl;
        return false;
    }

    Node<DATA> *cur = this->head;
    Node<DATA> *temp = new Node<DATA>(value);
    int counter = 0;

    while (counter < index - 1 && cur->Next != nullptr)
    {
        counter++;
        cur = cur->Next;
    }

    temp->Next = cur->Next;
    cur->Next = temp;

    return true;
}

/**
 * @brief Insert a new node in the certern place(Position)
 *
 * @tparam DATA ElementType
 * @param value Node's value
 * @param Position insert place
 * @return true 'Insert Sucessful'
 * @return false 'Insert Failed'
 */
template <class DATA>
bool LinkedList<DATA>::Insert(DATA &value, Node<DATA> *Position)
{
    Node<DATA> *newnode = new Node<DATA>(value);

    newnode->Next = Position->Next;
    Position->Next = newnode;
}

/**
 * @brief Find a Node
 *
 * @tparam DATA ElementType
 * @param value Node's value
 * @return Node<DATA>* The Position of Node
 */
template <class DATA>
Node<DATA> *LinkedList<DATA>::Find(DATA &value)
{
    Node<DATA> *cur = this->head->Next;
    while (cur->Next != nullptr && cur->value != value)
    {
        cur = cur->Next;
    }
    return cur;
}

/**
 * @brief Find the Previous Node
 *
 * @tparam DATA ElementType
 * @param value Node's value
 * @return Node<DATA>* The Position of Node
 */
template <class DATA>
Node<DATA> *LinkedList<DATA>::FindPrevious(DATA &value)
{
    Node<DATA> *cur = this->head;
    while (cur->Next != nullptr && cur->Next->value != value)
    {
        cur = cur->Next;
    }
    return cur;
}

/**
 * @brief Remove the First Node
 *
 * @tparam DATA ElementType
 * @param value Node's value
 */
template <class DATA>
void LinkedList<DATA>::Remove(DATA *value)
{
    Node<DATA> *cur = this->head->Next;
    this->head->Next = cur->Next;
    *value = cur->value;
    free(cur);
}

/**
 * @brief Remove the Position Node
 *
 * @tparam DATA ElementType
 * @param value Node's value
 * @param Poistion Node's posietion
 */
template <class DATA>
bool LinkedList<DATA>::Remove(DATA *value, Node<DATA> *Poistion)
{
    Node<DATA> *tempnode;
    if (!IsLast(Position))
    {
        tempnode = Position->Next;
        Position->next = tempnode->Next;
        free(tempnode);
    }
}

/**
 * @brief Remove the Node with value
 *
 * @tparam DATA ElementType
 * @param value Node's value
 */
template <class DATA>
bool LinkedList<DATA>::Remove(DATA &value)
{
    Node<DATA> *Position = FindPrevious(value);
    Node<DATA> *tempnode = new Node<DATA>();
    if (!IsLast(Position))
    {
        tempnode = Position->Next;
        Position->Next = tempnode->Next;
        delete tempnode;
    }
}

/**
 * @brief Remove LinkedList
 * 
 * @tparam DATA ElementType
 */
template <class DATA>
void LinkedList<DATA>::Clear()
{
    Node<DATA> *cur = this->head->Next;
    Node<DATA> *temp;
    this->head->Next = nullptr;
    while (cur != nullptr)
    {
        temp = cur->Next;
        free(cur);
        cur = temp;
    }
}

/**
 * @brief Traverse the Whole List
 * 
 * @tparam DATA ElementType
 * @param Function the method written by user
 */
template <class DATA>
void LinkedList<DATA>::Traverse(void (*Function)(DATA &value))
{
    Node<DATA> *cur = this->head->Next;
    while (cur != nullptr)
    {
        Function(cur->value);
        cur = cur->Next;
    }
}