#pragma once
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include <iostream>
// C++实现
/**
 * @brief 链表节点
 *
 * @tparam DATA 数据
 */
template <class DATA>
class Node
{
public:
    DATA value;
    Node<DATA> *Next;

    Node();
    Node(DATA &value);
};

template <class DATA>
class LinkedList : public Node<DATA>
{
private:
    Node<DATA> *head;

public:
    LinkedList();
    bool IsEmpty();
    bool IsLast(Node<DATA> *Position);
    int GetLen();

    void Insert(DATA &value);
    bool Insert(DATA &value, int index);
    bool Insert(DATA &value, Node<DATA> *Position);

    Node<DATA> *Find(DATA &value);
    Node<DATA> *FindPrevious(DATA &value);

    void Remove(DATA *value);
    bool Remove(DATA *value, Node<DATA> *Position);
    bool Remove(DATA &value);

    void Clear();
    void Traverse(void (*Function)(DATA &value));
};

#endif