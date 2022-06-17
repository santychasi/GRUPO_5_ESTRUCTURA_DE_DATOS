#pragma once
#ifndef _CIRCLE_DOUBLE_LINKED_LIST_
#define _CIRCLE_DOUBLE_LINKED_LIST_
#include "NodeList.h"
#include <functional>
#include <stdexcept>
using namespace std;
template <class T> class CircleDoubleLinkedList
{
  private:
    size_t size = 0;
    shared_ptr<NodeList<T>> head = nullptr;
    shared_ptr<NodeList<T>> at(size_t index) const;
    shared_ptr<NodeList<T>> last();

  public:
    CircleDoubleLinkedList() = default;
    void pushBack(T);
    void removeAt(size_t);
    void pushFront(T);
    void pushAt(size_t, T);
    void forEach(function<void(shared_ptr<NodeList<T>>, size_t)>);
    void forEach(function<void(T)>);
    shared_ptr<NodeList<T>> find(function<bool(shared_ptr<NodeList<T>>, size_t)>);
    shared_ptr<NodeList<T>> find(function<bool(T)>);
    shared_ptr<NodeList<T>> find(function<bool(T, size_t)>);
    size_t getSize() const;
};

template <class T> inline void CircleDoubleLinkedList<T>::pushBack(T value)
{
    size++;
    if (head == nullptr)
    {
        head = make_shared<NodeList<T>>(value);
        return;
    }
    auto lastNode = last();
    auto node = make_shared<NodeList<T>>(value);
    lastNode.get()->setNext(node);
    node.get()->setPrevious(lastNode);
}

template <typename T> inline void CircleDoubleLinkedList<T>::removeAt(size_t index)
{
    if (index < 0 || index >= size)
    {
        throw invalid_argument("index out of bounds");
    }

    if (index == 0)
    {
        shared_ptr<NodeList<T>> temp = head;
        head = head.get()->getNext();
        head.get()->setPrevious(nullptr);
        delete temp.get();
    }
    else if (index == size - 1)
    {
        shared_ptr<NodeList<T>> node = last();
        shared_ptr<NodeList<T>> previous = node.get()->getPrevious();
        previous.get()->setNext(nullptr);
        delete node.get();
    }
    else
    {
        shared_ptr<NodeList<T>> target = at(index);
        shared_ptr<NodeList<T>> previous = target.get()->getPrevious();
        shared_ptr<NodeList<T>> next = target.get()->getNext();

        previous.get()->setNext(next);
        next.get()->setPrevious(previous);
        delete target.get();
    }

    size--;
}

template <class T> inline void CircleDoubleLinkedList<T>::pushFront(T value)
{
    if (head == nullptr)
    {
        return pushBack(value);
    }

    shared_ptr<NodeList<T>> node = make_shared<NodeList<T>>(value);
    shared_ptr<NodeList<T>> temp = head;

    head = node;
    head.get()->setNext(temp);
    temp.get()->setPrevious(head);
    size++;
}

template <class T> inline void CircleDoubleLinkedList<T>::pushAt(size_t index, T value)
{
    if (index < 0 || index > size)
    {
        throw invalid_argument("index out of bounds");
    }

    if (index == 0 || size == 0)
    {
        return pushFront(value);
    }
    else if (index == size)
    {
        return pushBack(value);
    }

    shared_ptr<NodeList<T>> target = at(index);
    shared_ptr<NodeList<T>> previous = target.get()->getPrevious();
    shared_ptr<NodeList<T>> next = target.get()->getNext();
    shared_ptr<NodeList<T>> nodo = make_shared<NodeList<T>>(value);

    previous.get()->setNext(nodo);
    nodo.get()->setNext(target);
    nodo.get()->setPrevious(previous);
    target.get()->setPrevious(nodo);
    size++;
}
#endif
template <class T>
inline void CircleDoubleLinkedList<T>::forEach(function<void(shared_ptr<NodeList<T>>, size_t)> callback)
{
    auto current = head;
    size_t index = 0;
    while (current != nullptr)
    {
        callback(current, index);
        current = current.get()->getNext();
        index++;
    }
}
template <class T> inline void CircleDoubleLinkedList<T>::forEach(function<void(T)> callback)
{
    forEach([&](shared_ptr<NodeList<T>> node, size_t index) { callback(node.get()->getData()); });
}

template <class T>
inline shared_ptr<NodeList<T>> CircleDoubleLinkedList<T>::find(function<bool(shared_ptr<NodeList<T>>, size_t)> callback)
{
    shared_ptr<NodeList<T>> current = head;

    int index = 0;

    while (current != nullptr)
    {
        if (callback(current, index++))
        {
            return current;
        }

        current = current.get()->getNext();
    }

    return nullptr;
}
template <typename T> inline shared_ptr<NodeList<T>> CircleDoubleLinkedList<T>::find(function<bool(T)> callback)
{
    return find([&](shared_ptr<NodeList<T>> node, size_t index) { return callback(node.get()->getData()); });
}
template <class T> inline size_t CircleDoubleLinkedList<T>::getSize() const
{
    return size;
}
template <class T> inline shared_ptr<NodeList<T>> CircleDoubleLinkedList<T>::last()
{
    if (size == 0)
    {
        return nullptr;
    }
    return at(size - 1);
}

template <class T> shared_ptr<NodeList<T>> CircleDoubleLinkedList<T>::at(size_t index) const
{
    if (index < 0 || index >= size)
    {
        throw invalid_argument("index out of bounds");
    }
    if (index == 0)
    {
        return head;
    }

    size_t currentIndex = 0;
    shared_ptr<NodeList<T>> lastNode = head;
    while (lastNode.get()->getNext() != nullptr)
    {
        if (currentIndex == index)
        {
            break;
        }
        currentIndex++;
        lastNode = lastNode.get()->getNext();
    }
    return lastNode;
}

template <typename T> shared_ptr<NodeList<T>> CircleDoubleLinkedList<T>::find(function<bool(T, size_t)> callback)
{
    return find(
        [&](shared_ptr<NodeList<T>> node, size_t index) -> bool { return callback(node.get()->getData(), index); });
}
