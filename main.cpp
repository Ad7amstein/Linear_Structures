#include "main.h"
/**
 * main - Entry point
 *
 * @return Success (0)
 */
int main(void)
{
    map<char, void (*)()> Test;
    Test = {
        // {'1', Test_Array_Based_List},
        {'2', Test_Singly_Linked_list},
        // {'3', Test_Doubly_Linked_list},
        // {'4', Test_Circular_Linked_List},
        // {'5', Test_Stack},
        // {'6', Test_Queu}
    };
    char choice;

    do
    {
    printf("Choose test number: \n");
    cout << "1.Test Array Based List.\n"
         << "2.Test Singly Linked list.\n"
         << "3.Test Doubly Linked list\n"
         << "4.Test Circular Linked List\n"
         << "5.Test Stack\n"
         << "6.Test Queu\n";
    cout << "Enter your choice here: ";
    cin >> choice;
    } while (choice < '1' || choice > '6');

    cout << "Start Testing...\n\n";
    Test[choice]();
    return (0);
}
