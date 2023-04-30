#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
/**
 * struct singly_linked_list - singly linked list
 * @param n: typename (T)
 * @param next: points to the next node
 *
 * Description: singly linked list node structure
 */
template <typename T>
struct singly_linked_list_node
{
    T n;
    struct singly_linked_list_node<T> *next;
};
// template <typename T>
// using singly_list_t = singly_linked_list<T>;

template <typename T>
class singly_linked_list
{
public:
    singly_linked_list() : head(nullptr) {} // DONE
    void insertAtHead(T element); // DONE
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int firstItemIdx, int secondItemIdx); // swap two nodes without swapping data.
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print(); // DONE
private:
    singly_linked_list_node<T> *head;
};

#endif /* MAIN_H */