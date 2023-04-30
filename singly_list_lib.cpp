#include "main.h"
using namespace std;
/**
 * insertAtHead - inset element to the beggining of the list
 *
 * @tparam T: Element datatype
 * @param element: Element to be inserted
 */
template <typename T>
void singly_linked_list<T>::insertAtHead(T element)
{
    singly_linked_list_node<T> *node = new singly_linked_list_node<T>();

    if (node == nullptr)
        printf("Failed!, Not enough memory");

    node->n = element;
    if (head == nullptr)
        node->next = nullptr;
    else
        node->next = head;

    head = node;
}

/**
 * print - Print list elements
 *
 * @tparam T: Elements datatype
 */
template <typename T>
void singly_linked_list<T>::print()
{
    while (head)
    {
        cout << head->n << endl;
        head = head->next;
    }
}

/**
 * insertAtTail - inset element to the end of the list
 *
 * @tparam T: Element datatype
 * @param element: Element to be inserted
 */
template <typename T>
void singly_linked_list<T>::insertAtTail(T element)
{
    singly_linked_list_node<T> *node = new singly_linked_list_node<T>(), *last = head;

    
}