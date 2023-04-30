#include "main.h"
/**
 * Test_Singly_Linked_list - function to test
 * singly linked list
 */
void Test_Singly_Linked_list()
{
    singly_linked_list<int> list;
    cout << (list.isEmpty() ? "List is Empty" : "List not Empty") << endl;
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(3);
    list.insertAtHead(0);
    list.insertAtTail(4);
    list.removeAtHead();
    list.print();
    cout << "---------------------------------------\n";
    printf("4: %s\n", list.isExist(4) ? "YES" : "NO");
    printf("5: %s\n", list.isExist(5) ? "YES" : "NO");
    cout << "list size: " << list.linkedListSize() << endl;
    list.insertAtTail(5);
    list.insertAtHead(0);
    list.print();
    cout << "---------------------------------------\n";
    list.removeAtTail();
    list.insertAtTail(9);
    list.print();
    cout << "---------------------------------------\n";
    cout << (list.isEmpty() ? "List is Empty" : "List not Empty") << endl;
    list.clear();
    list.print();
    cout << (list.isEmpty() ? "List is Empty" : "List not Empty") << endl;
    printf("1: %s\n", list.isExist(1) ? "YES" : "NO");
}
