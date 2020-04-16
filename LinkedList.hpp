#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::ostream;

template <typename T>
class Node{
public:
        Node(T newData, Node<T> *newNext = nullptr);
        template <typename U>
        friend ostream& operator<<(ostream& os, const Node<U>& n);
        T getData(){ return data; }
        Node<T>* getNext(){ return next; }
        void setNext(Node<T> *nnext){ next = nnext; }
private:
        T data;
        Node<T> *next;
};

template <typename T>
class LinkedList{
public:
        LinkedList(T data);
        template <typename U>
        friend ostream& operator<<(ostream &os, const LinkedList<U> &l);
        void add(T data, int position = -1);
        void remove(T data);

private:
        Node<T> *firstNode;
};

template <typename T>
ostream& operator<<(ostream &os, const LinkedList<T> &l){
        if(l.firstNode == nullptr){
                os << "[ ]";
                return os;
        }
        os << "[ " << l.firstNode->getData();
        Node<T> *currentNode = l.firstNode->getNext();
        while(currentNode != nullptr){
                os << ", " << currentNode->getData();
                currentNode = currentNode->getNext();
        }
        os << " ]";
        return os;
}

template <typename T>
ostream& operator<<(ostream& os, const Node<T> &n){
        os << n.getData();
        return os;
}


#endif
