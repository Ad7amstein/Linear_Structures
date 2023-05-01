#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
void Test_Array_Based_List();
void Test_Singly_Linked_list();
void Test_doubly_linked_list();
void Test_Circular_Linked_List();
void Test_Stack();
void Test_Queu();

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

/**
 * struct doubly_linked_list - doubly linked list
 * @param n: typename (T)
 * @param next: points to the next node
 * @param prev: points to the previous node
 *
 * Description: doubly linked list node structure
 */
template <typename T>
struct doubly_linked_list_node
{
    T n;
    struct doubly_linked_list_node<T> *next;
    struct doubly_linked_list_node<T> *prev;
};

template <typename T>
class doubly_linked_list
{
public:
    doubly_linked_list() : head(nullptr), tail(nullptr), size(0) {} // DONE
    void insertAtHead(T element);                                   // DONE
    void insertAtTail(T element);                                   // DONE
    void insertAt(T element, int index);                            // DONE
    void removeAtHead();                                            // DONE
    void removeAtTail();                                            // DONE
    void removeAt(int index);                                       // DONE
    T retrieveAt(int index);                                        // DONE
    void replaceAt(T newElement, int index);                        // DONE
    bool isExist(T element);                                        // DONE
    bool isItemAtEqual(T element, int index);                       // DONE
    void swap(int firstItemIdx, int secondItemIdx);
    void reverse();             // DONE
    bool isEmpty();             // DONE
    int doubleLinkedListSize(); // DONE
    void clear();               // DONE
    void forwardTraversal();    // DONE
    void backwardTraversal();   // DONE

private:
    int size;
    doubly_linked_list_node<T> *head;
    doubly_linked_list_node<T> *tail;
};

template <typename T>
class singly_linked_list
{
public:
    singly_linked_list() : head(nullptr), size(0) {} // DONE
    void insertAtHead(T element);                    // DONE
    void insertAtTail(T element);                    // DONE
    void insertAt(T element, int index);             // DONE
    void removeAtHead();                             // DONE
    void removeAtTail();                             // DONE
    void removeAt(int index);                        // DONE
    T retrieveAt(int index);                         // DONE
    void replaceAt(T newElement, int index);         // DONE
    bool isExist(T element);                         // DONE
    bool isItemAtEqual(T element, int index);        // DONE
    void swap(int firstItemIdx, int secondItemIdx);  // DONE
    bool isEmpty();                                  // DONE
    int linkedListSize();                            // DONE
    void clear();                                    // DONE
    void print();                                    // DONE
private:
    singly_linked_list_node<T> *head;
    int size;
};
#include "singly_list_lib.h"
#include "doubly_list_lib.h"
#endif /* MAIN_H */