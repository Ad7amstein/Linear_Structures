#ifndef SINGLY_LIST_LIB_H
#define SINGLY_LIST_LIB_H
#include "main.h"
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
    {
        printf("Failed!, Not enough memory");
        exit(98);
    }

    node->n = element;
    if (head == nullptr)
        node->next = nullptr;
    else
        node->next = head;

    head = node;
    size++;
}

/**
 * print - Print list elements
 *
 * @tparam T: Elements datatype
 */
template <typename T>
void singly_linked_list<T>::print()
{
    singly_linked_list_node<T> *node = head;

    while (node)
    {
        cout << node->n << endl;
        node = node->next;
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
    singly_linked_list_node<T> *node = new singly_linked_list_node<T>(), *last;
    if (node == nullptr)
    {
        printf("Failed!, Not enough memory");
        exit(98);
    }

    node->n = element;
    node->next = nullptr;

    if (head == nullptr)
        head = node;
    else
    {
        last = head;
        while (last->next)
            last = last->next;

        last->next = node;
    }
    size++;
}

/**
 * linkedListSize - Return list size
 *
 * @tparam T: Elements datatype
 * @return List size (int)
 */
template <typename T>
int singly_linked_list<T>::linkedListSize()
{
    return (size);
}

/**
 * isEmpty - Check if the list is empty or not
 *
 * @tparam T: elements datatype
 * @return true if list is empty
 * @return false if list is not empty
 */
template <typename T>
bool singly_linked_list<T>::isEmpty()
{
    return (size == 0);
}

/**
 * clear - clear the list
 *
 * @tparam T: elements datatype
 */
template <typename T>
void singly_linked_list<T>::clear()
{
    size = 0;
    head = nullptr;
}

/**
 * isExist - Check if an element is existed in the list or not
 *
 * @tparam T: Element datatype
 * @param element: Element to be checked
 * @return true if the element is exists
 * @return false if the element is not exists
 */
template <typename T>
bool singly_linked_list<T>::isExist(T element)
{
    singly_linked_list_node<T> *node = head;

    while (node)
    {
        if (node->n == element)
            return (true);
        node = node->next;
    }

    return (false);
}

/**
 * removeAtTail - Remove the last element from the list
 *
 * @tparam T: Element datatype
 */
template <typename T>
void singly_linked_list<T>::removeAtTail()
{
    singly_linked_list_node<T> *node = head;

    if (head == nullptr)
        return;

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        while (node->next->next)
            node = node->next;

        delete (node->next);
        node->next = nullptr;
    }
    size--;
}

/**
 * removeAtHead - Remove the first element
 *
 * @tparam T: Element datatype
 */
template <typename T>
void singly_linked_list<T>::removeAtHead()
{
    singly_linked_list_node<T> *node = head;
    if (head == nullptr)
        return;

    head = head->next;
    delete (node);
    node = nullptr;
    size--;
}

#endif /* SINGLY_LIST_LIB_H */