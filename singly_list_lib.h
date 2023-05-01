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

/**
 * retrieveAt - function that returns
 * the nth node of a linked list.
 *
 * @tparam T: Element datatype
 * @param index: Element position
 * @return T: Element value
 */
template <typename T>
T singly_linked_list<T>::retrieveAt(int index)
{
	singly_linked_list_node<T> *node = head;

	if (index < 0 || index > (size - 1))
	{
		cout << "Error, index out of range!\n";
		exit(100);
	}

	while (index--)
		node = node->next;

	return (node->n);
}

/**
 * replaceAt - Replace the value at the index n with a new value (newElement)
 *
 * @tparam T: Element datatype
 * @param newElement: The New element
 * @param index: The position of the index
 */
template <typename T>
void singly_linked_list<T>::replaceAt(T newElement, int index)
{
	singly_linked_list_node<T> *node = head;

	if (index < 0 || index > (size - 1))
	{
		cout << "Error, index out of range!\n";
		exit(100);
	}

	while (index--)
		node = node->next;

	node->n = newElement;
}

/**
 * isItemAtEqual - Check if the Item at index (index)
 * is equal to the element (elemtn) or not
 *
 * @tparam T: Element datatype
 * @param element: Element to be compare with
 * @param index: Position of the element
 * @return true: if the two elements is equal
 * @return false: Otherwise
 */
template <typename T>
bool singly_linked_list<T>::isItemAtEqual(T element, int index)
{
	singly_linked_list_node<T> *node = head;

	if (index < 0 || index > (size - 1))
	{
		cout << "Error, index out of range!\n";
		exit(100);
	}

	while (index--)
		node = node->next;

	return (node->n == element);
}

/**
 * insertAt - function that inserts a new node
 * at a given position.
 *
 * @tparam T: Element datatype
 * @param element: New element to be inserteded
 * @param index: Position of the new element
 */
template <typename T>
void singly_linked_list<T>::insertAt(T element, int index)
{
	singly_linked_list_node<T> *new_node = new singly_linked_list_node<T>(), *curr = head, *prev = nullptr;

	if (new_node == nullptr)
	{
		printf("Failed!, Not enough memory");
		exit(98);
	}

	new_node->n = element;
	new_node->next = nullptr;
	if (index < 0 || index > size)
	{
		cout << "Error, index out of range!\n";
		exit(100);
	}
	if (index == 0)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		while (index--)
		{
			prev = curr;
			curr = curr->next;
		}
		new_node->next = curr;
		prev->next = new_node;
	}
	size++;
}

/**
 * removeAt - Remove an element at position (index)
 *
 * @tparam T: Element datatype
 * @param index: Position of the element
 */
template <typename T>
void singly_linked_list<T>::removeAt(int index)
{
	singly_linked_list_node<T> *prev, *cur, *temp;

	if (head == nullptr)
	{
		cout << "List is empty!\n";
		exit(100);
	}

	if (index == 0)
	{
		temp = head;
		head = head->next;
		delete temp;
		size--;
		return;
	}

	prev = head;
	cur = head->next;
	while (cur != NULL && index > 1)
	{
		prev = cur;
		cur = cur->next;
		--index;
	}

	if (index > 1 || cur == NULL)
	{
		cout << "Error, index out of range!\n";
		exit(100);
	}

	prev->next = cur->next;
	delete cur;
	size--;
}

/**
 * swap - Swap to nodes
 *
 * @tparam T: Element datatype
 * @param firstItemIdx: Position of the first node
 * @param secondItemIdx: Position of the second node
 */
template <typename T>
void singly_linked_list<T>::swap(int firstItemIdx, int secondItemIdx)
{
	singly_linked_list_node<T> *prev1 = nullptr, *curr1 = head;
	singly_linked_list_node<T> *prev2 = nullptr, *curr2 = head;
	if (firstItemIdx == secondItemIdx)
		return;

	if ((firstItemIdx < 0 || firstItemIdx > (size - 1)) || (secondItemIdx < 0 || secondItemIdx > (size - 1)))
	{
		cout << "Error, index out of range!\n";
		exit(100);
	}

	if (firstItemIdx > secondItemIdx)
		std::swap(firstItemIdx, secondItemIdx);
	else if (firstItemIdx == secondItemIdx)
		return;

	for (int i = 0; i < firstItemIdx; i++)
	{
		prev1 = curr1;
		curr1 = curr1->next;
	}

	for (int i = 0; i < secondItemIdx; i++)
	{
		prev2 = curr2;
		curr2 = curr2->next;
	}

	singly_linked_list_node<T> *temp = curr2->next;
	if (curr2 != curr1->next)
		curr2->next = curr1->next;
	else
		curr2->next = curr1;

	curr1->next = temp;

	if (prev1)
		prev1->next = curr2;
	else
		head = curr2;

	if (prev2 != curr1)
		prev2->next = curr1;
}
#endif /* SINGLY_LIST_LIB_H */