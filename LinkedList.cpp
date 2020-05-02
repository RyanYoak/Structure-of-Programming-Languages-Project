#include <iostream>
#include <string>
#include "LinkedList.hpp"

/*
* Here the value of newData will be passed by value, and not passed by reference, a local instance of the
* data will be created and assigned to data. However, newNext is a pointer and is how c++ allows pass by
* reference.
*/
template <typename T>
Node<T>::Node(T newData, Node<T> *newNext){
        data = newData;
        next = newNext;
}


template <typename T>
LinkedList<T>::LinkedList(T data){
        firstNode = new Node<T>(data);
}

/*
* Here one can see how C++ is statically typed, when a new variable is declared the type, 'Node<T>', must be declared
* here before compilation.
*/
template <typename T>
void LinkedList<T>::add(T data, int position){
        Node<T> *node = new Node<T>(data);
        Node<T> *currentNode = firstNode;
        if(position < 0){
                while(currentNode->getNext() != nullptr){
                        currentNode = currentNode->getNext();
                }
                currentNode->setNext(node);
        }
        else{
                if(position == 0){
                        node->setNext(firstNode);
                        firstNode = node;
                        return;
                }
                int counter = 1;
                while(counter != position){
                        if(currentNode->getNext() == nullptr){
                                currentNode->setNext(node);
                                return;
                        }
                        currentNode = currentNode->getNext();
                        ++counter;
                }
                node->setNext(currentNode->getNext());
                currentNode->setNext(node);
        }
 }

/*
* Here when a node is removed the 'delete' keyword must be used, in C++ data must be manually
* assigned to the heap as well as removed from it by the programmer.
*/
 template <typename T>
 void LinkedList<T>::remove(T data){
         if(firstNode->getData() == data){
                 Node<T> *temp = firstNode;
                 delete firstNode;
                 firstNode = firstNode->getNext();
         }
         Node<T> *previousNode = firstNode;
         Node<T> *currentNode = firstNode->getNext();
         while(currentNode->getData() != data){
                 if(currentNode->getNext() == nullptr){
                         return;
                 }
                 currentNode = currentNode->getNext();
                 previousNode = previousNode->getNext();
         }
         Node<T> *temp = currentNode;
         previousNode->setNext(currentNode->getNext());
         delete temp;
 }


 int main(){

 LinkedList<int> ll(1);
 ll.add(2);
 ll.add(3);
 ll.add(4);
 ll.add(5,1);

 cout << ll << endl;

 ll.remove(5);

 cout << ll << endl;

 }
