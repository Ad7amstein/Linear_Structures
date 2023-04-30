#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
void Test_Array_Based_List();
void Test_Singly_Linked_list();
inline void Test_Doubly_Linked_list();
inline void Test_Circular_Linked_List();
inline void Test_Stack();
inline void Test_Queu();

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
    singly_linked_list() : head(nullptr), size(0) {} // DONE
    void insertAtHead(T element);                    // DONE
    void insertAtTail(T element);                    // DONE
    void insertAt(T element, int index);
    void removeAtHead(); // DONE
    void removeAtTail(); // DONE
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element); // DONE
    bool isItemAtEqual(T element, int index);
    void swap(int firstItemIdx, int secondItemIdx); // swap two nodes without swapping data.
    bool isEmpty();                                 // DONE
    int linkedListSize();                           // DONE
    void clear();                                   // DONE
    void print();                                   // DONE
private:
    singly_linked_list_node<T> *head;
    int size;
};

#include "singly_list_lib.h"
#endif /* MAIN_H */