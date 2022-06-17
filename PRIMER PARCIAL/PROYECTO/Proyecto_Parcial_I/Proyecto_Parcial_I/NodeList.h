#pragma once
#include <memory>
using namespace std;
template <class T> class NodeList
{
  private:
    T data;
    shared_ptr<NodeList<T>> next;
    shared_ptr<NodeList<T>> previous;

  public:
    NodeList(T);
    void setData(T);
    void setNext(shared_ptr<NodeList<T>>);
    void setPrevious(shared_ptr<NodeList<T>>);
    shared_ptr<NodeList<T>> getNext();
    shared_ptr<NodeList<T>> getPrevious();
    T getData();
};

template <class T> NodeList<T>::NodeList(T data)
{
    this->data = data;
    this->next = nullptr;
    this->previous = nullptr;
}
template <class T> void NodeList<T>::setData(T data)
{
    this->data = data;
}
template <class T> void NodeList<T>::setNext(shared_ptr<NodeList<T>> next)
{
    this->next = next;
}
template <class T> void NodeList<T>::setPrevious(shared_ptr<NodeList<T>> previous)
{
    this->previous = previous;
}

template <class T> shared_ptr<NodeList<T>> NodeList<T>::getNext()
{
    return this->next;
}

template <class T> shared_ptr<NodeList<T>> NodeList<T>::getPrevious()
{
    return this->previous;
}

template <class T> T NodeList<T>::getData()
{
    return this->data;
}
