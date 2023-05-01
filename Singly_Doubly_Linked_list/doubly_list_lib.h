#ifndef DOUBLY_LIST_LIB_H
#define DOUBLY_LIST_LIB_H
#include "main.h"
/**
 * insertAtHead - inset element to the beggining of the list
 *
 * @tparam T: Element datatype
 * @param element: Element to be inserted
 */
template <typename T>
void doubly_linked_list<T>::insertAtHead(T element)
{
    doubly_linked_list_node<T> *node = new doubly_linked_list_node<T>();

    if (node == nullptr)
    {
        printf("Failed!, Not enough memory");
        exit(98);
    }

    node->n = element;
    node->prev = nullptr;

    if (head == nullptr)
    {
        head = node;
        tail = node;
        node->next = nullptr;
    }
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
}

/**
 * insertAtTail - inset element to the end of the list
 *
 * @tparam T: Element datatype
 * @param element: Element to be inserted
 */
template <typename T>
void doubly_linked_list<T>::insertAtTail(T element)
{
    doubly_linked_list_node<T> *node = new doubly_linked_list_node<T>();

    if (node == nullptr)
    {
        printf("Failed!, Not enough memory");
        exit(98);
    }

    node->n = element;
    node->next = nullptr;

    if (tail == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    size++;
}

/**
 * insertAt - insert element at the given index in the list
 *
 * @tparam T: Element datatype
 * @param element: Element to be inserted
 * @param index: Index where the element is to be inserted
 */
template <typename T>
void doubly_linked_list<T>::insertAt(T element, int index)
{
    if (index < 0 || index > size)
    {
        printf("Index out of range!\n");
        exit(100);
    }

    if (index == 0)
    {
        insertAtHead(element);
        return;
    }

    if (index == size)
    {
        insertAtTail(element);
        return;
    }

    doubly_linked_list_node<T> *node = new doubly_linked_list_node<T>();
    if (node == nullptr)
    {
        printf("Failed!, Not enough memory");
        exit(98);
    }

    node->n = element;

    doubly_linked_list_node<T> *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node;
    temp->next = node;

    size++;
}

/**
 * forwardTraversal - Print list elements from head to tail
 *
 * @tparam T: Elements datatype
 */
template <typename T>
void doubly_linked_list<T>::forwardTraversal()
{
    doubly_linked_list_node<T> *node = head;

    while (node)
    {
        cout << node->n << endl;
        node = node->next;
    }
}

/**
 * backwardTraversal - Print list elements from tail to head
 *
 * @tparam T: Elements datatype
 */
template <typename T>
void doubly_linked_list<T>::backwardTraversal()
{
    doubly_linked_list_node<T> *node = tail;

    while (node)
    {
        cout << node->n << endl;
        node = node->prev;
    }
}

/**
 * doubleLinkedListSize - Return list size
 *
 * @tparam T: Elements datatype
 * @return List size (int)
 */
template <typename T>
int doubly_linked_list<T>::doubleLinkedListSize()
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
bool doubly_linked_list<T>::isEmpty()
{
    return (size == 0);
}

/**
 * removeAtHead - removes the head element of the list
 *
 * @tparam T: Element datatype
 */
template <typename T>
void doubly_linked_list<T>::removeAtHead()
{
    if (head == nullptr)
    {
        printf("Failed!, list is empty");
        exit(98);
    }

    doubly_linked_list_node<T> *temp = head;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    size--;
}

/**
 * removeAtTail - removes the tail element of the list
 *
 * @tparam T: Element datatype
 */
template <typename T>
void doubly_linked_list<T>::removeAtTail()
{
    if (tail == nullptr)
    {
        printf("Failed!, list is empty");
        exit(98);
    }

    doubly_linked_list_node<T> *temp = tail;

    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    size--;
}

/**
 * removeAt - removes the element at the given index of the list
 *
 * @tparam T: Element datatype
 * @param index: Index of the element to remove
 */
template <typename T>
void doubly_linked_list<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        printf("Failed!, index is out of bounds");
        exit(98);
    }

    if (index == 0)
    {
        removeAtHead();
    }
    else if (index == size - 1)
    {
        removeAtTail();
    }
    else
    {
        doubly_linked_list_node<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }
}

/**
 * isExist - Check if the element is in the list
 *
 * @tparam T: Element datatype
 * @param element: Element to be checked
 * @return true if element is found, false otherwise
 */
template <typename T>
bool doubly_linked_list<T>::isExist(T element)
{
    doubly_linked_list_node<T> *current = head;

    while (current != nullptr)
    {
        if (current->n == element)
            return true;
        current = current->next;
    }

    return false;
}

/**
 * isItemAtEqual - Check if the element at given index is equal to the given element
 *
 * @tparam T: Element datatype
 * @param element: Element to be checked
 * @param index: Index of the element to be compared
 * @return true if the element is found and equal to the given element, false otherwise
 */
template <typename T>
bool doubly_linked_list<T>::isItemAtEqual(T element, int index)
{
    if (index < 0 || index >= size)
    {
        printf("Failed!, index is out of bounds");
        exit(98);
    }

    doubly_linked_list_node<T> *current = head;
    int i = 0;

    while (current != nullptr && i != index)
    {
        current = current->next;
        i++;
    }

    return (current->n == element);
}

template <typename T>
void doubly_linked_list<T>::clear()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

/**
 * retrieveAt - retrieve element at the specified index
 *
 * @tparam T: Element datatype
 * @param index: Index of the element to retrieve
 *
 * @return Element at the specified index
 */
template <typename T>
T doubly_linked_list<T>::retrieveAt(int index)
{
    if (index < 0 || index >= size)
    {
        printf("Invalid index specified");
        exit(98);
    }

    int i = 0;
    doubly_linked_list_node<T> *current = head;

    while (i < index)
    {
        current = current->next;
        i++;
    }

    return (current->n);
}

/**
 * replaceAt - replace element at the specified index with new element
 *
 * @tparam T: Element datatype
 * @param newElement: New element to be inserted
 * @param index: Index of the element to be replaced
 */
template <typename T>
void doubly_linked_list<T>::replaceAt(T newElement, int index)
{
    if (index < 0 || index >= size)
    {
        printf("Invalid index specified");
        exit(98);
    }

    int i = 0;
    doubly_linked_list_node<T> *current = head;

    while (i < index)
    {
        current = current->next;
        i++;
    }

    current->n = newElement;
}

/**
 * swap - 
 * 
 * @tparam T 
 * @param firstItemIdx 
 * @param secondItemIdx 
 */
template <typename T>
void doubly_linked_list<T>::swap(int firstItemIdx, int secondItemIdx)
{
    if ((firstItemIdx < 0 || firstItemIdx > (size - 1)) || (secondItemIdx < 0 || secondItemIdx > (size - 1)))
    {
        cout << "Error, index out of range!\n";
        exit(100);
    }

    if (firstItemIdx == secondItemIdx)
        return;

    if (firstItemIdx > secondItemIdx)
        std::swap(firstItemIdx, secondItemIdx);

    doubly_linked_list_node<T> *firstNode = head, *secondNode = head;

    cout << "Here1\n";
    for (int i = 0; i < firstItemIdx; i++)
    {
        firstNode = firstNode->next;
    }

    for (int i = 0; i < secondItemIdx; i++)
    {
        secondNode = secondNode->next;
    }
    cout << "Here2\n";
    cout << firstNode->n << endl;
    cout << secondNode->n << endl;

    // Swap the prev pointers
    doubly_linked_list_node<T> *tempPrev = firstNode->prev;
    firstNode->prev = secondNode->prev;
    secondNode->prev = tempPrev;

    cout << "Here3\n";
    // Swap the next pointers
    doubly_linked_list_node<T> *tempNext = firstNode->next;
    firstNode->next = secondNode->next;
    secondNode->next = tempNext;

    cout << "Here4\n";
    // Update the head and tail pointers if necessary
    if (firstNode->prev == nullptr)
    {
        head = firstNode;
    }
    if (secondNode->prev == nullptr)
    {
        head = secondNode;
    }
    if (firstNode->next == nullptr)
    {
        tail = firstNode;
    }
    if (secondNode->next == nullptr)
    {
        tail = secondNode;
    }

    // Update the prev and next pointers of the neighboring nodes
    if (firstNode->prev != nullptr)
    {
        firstNode->prev->next = secondNode;
    }
    if (firstNode->next != nullptr)
    {
        firstNode->next->prev = secondNode;
    }
    if (secondNode->prev != nullptr)
    {
        secondNode->prev->next = firstNode;
    }
    if (secondNode->next != nullptr)
    {
        secondNode->next->prev = firstNode;
    }
}

template <typename T>
void doubly_linked_list<T>::reverse()
{
    if (head == nullptr || head->next == nullptr)
        return;

    doubly_linked_list_node<T> *currentNode = head;
    tail = head;

    while (currentNode != nullptr)
    {
        std::swap(currentNode->prev, currentNode->next);
        currentNode = currentNode->prev;

        if (currentNode != nullptr && currentNode->prev == nullptr)
            head = currentNode;
    }
}

#endif /* DOUBLY_LIST_LIB_H */