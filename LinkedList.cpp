#include <iostream>
#include <string>
#include "LinkedList.hpp"


template <typename T>
Node<T>::Node(T newData, Node<T> *newNext){
        data = newData;
        next = newNext;
}


template <typename T>
LinkedList<T>::LinkedList(T data){
        firstNode = new Node<T>(data);
}

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
