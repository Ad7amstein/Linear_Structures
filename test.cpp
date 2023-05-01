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
    cout << "---------------------------------------\n";
    printf("list[0] %s 0\n", list.isItemAtEqual(0, 0) ? "=" : "!=");
    // printf("list[4] %s 4\n", list.isItemAtEqual(4, 4) ? "=" : "!="); out of range
    printf("list[0] %s 1\n", list.isItemAtEqual(1, 0) ? "=" : "!=");
    // printf("list[9] %s 8\n", list.isItemAtEqual(8, 9) ? "=" : "!="); out of range
    cout << "---------------------------------------\n";
    cout << "list size: " << list.linkedListSize() << endl;
    list.insertAtTail(5);
    list.insertAtHead(0);
    list.print();
    cout << "---------------------------------------\n";
    list.removeAtTail();
    list.insertAtTail(9);
    list.print();
    cout << "---------------------------------------\n";
    printf("list[0] = %d\n", list.retrieveAt(0));
    printf("list[5] = %d\n", list.retrieveAt(5));
    printf("list[3] = %d\n", list.retrieveAt(3));
    // printf("list[6] = %d\n", list.retrieveAt(6)); out of range
    cout << "---------------------------------------\n";
    list.replaceAt(-1, 0);
    list.replaceAt(5, 5);
    list.replaceAt(3, 1);
    // list.replaceAt(3, -1); out of range
    // list.replaceAt(3, 9); out of range
    list.print();
    cout << "---------------------------------------\n";
    cout << (list.isEmpty() ? "List is Empty" : "List not Empty") << endl;
    list.clear();
    list.print();
    // list.removeAt(0); // list is empty
    cout << (list.isEmpty() ? "List is Empty" : "List not Empty") << endl;
    printf("1: %s\n", list.isExist(1) ? "YES" : "NO");
    cout << "---------------------------------------\n";
    list.insertAt(3, 0);
    list.insertAt(4, 1);
    // list.insertAt(8, 5);
    list.insertAt(5, 2);
    list.insertAt(2, 0);
    list.insertAt(1, 0);
    list.insertAt(0, 0);
    // list.insertAt(3, 100);
    list.print();
    cout << "---------------------------------------\n";
    // list.removeAt(-1); // out of range
    // list.removeAt(8); // out of range
    list.removeAt(0);
    list.print();
    cout << "list size: " << list.linkedListSize() << endl;
    cout << "---------------------------------------\n";
    cout << "Swap1: \n";
    list.swap(1, 3); // DONE
    list.print();
    cout << "Swap2: \n";
    list.swap(1, 1); // DONE
    list.print();
    cout << "Swap3: \n";
    list.swap(0, 4); // DONE
    list.print();
    cout << "Swap4: \n";
    list.swap(0, 1); // DONE
    list.print();
    cout << "Swap5: \n";
    list.swap(1, 2); // DONE
    list.print();

}
