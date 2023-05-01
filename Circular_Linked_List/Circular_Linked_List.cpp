#include<bits/stdc++.h>
using namespace std;
//================================================================
void FILES ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
//================================================================
template<typename T>
struct node
{
    T date;
    node * next;
    node(T value):date(value) {};
};
template<typename T>
class Circular_Linked_List
{
    node<T> *head;
    node<T> *tail;
    int length;

public:

    Circular_Linked_List()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    bool isEmpty()
    {
        return (length == 0);
    }
    void insertAtHead (T value)
    {
        node<T> *item; item = new node<T>(value);
        if(isEmpty())
        {
            head = tail = item;
        }
        else
        {
            item->next = head;
            head = item;
        }
        length++;
        tail->next = item;
    }
    void insertAtEnd (T value)
    {
        node<T> *item ; item = new node<T>(value);
        if(isEmpty())
        {
            head = tail = item;
        }
        else
        {
            tail ->next = item;
            tail = item;
        }
        length++;
        tail -> next = head;

    }
    void removeAtHead()
    {
        if(!isEmpty())
        {
            head = head->next;
            tail->next = head;
            length --;
        }
        else
            cout << "the list is empty "<< endl;
    }
    void removeAtEnd ()
    {
        if(!isEmpty())
        {
            int i = 1 ;
            node<T> *cnt = head;
            for( ;i < length ; cnt = cnt->next,i++);
            cnt->next = head;
            length--;
        }
    }
    void removeAt (int index)
    {
        if(index == 0 )
            removeAtHead();
        else if(index < length-1)
        {
             int i = 1 ;
            node<T> *cnt = head;
            for( ;i < index ; cnt = cnt->next,i++);
            cnt->next = cnt->next->next;
            length--;
        }
        else if(index == length-1 )
            removeAtEnd();
    }
    T retrieveAt(int index)
    {
        if(index < length)
        {
            int i = 0 ;
            node<T> *cnt = head;
            for( ;i < index ; cnt = cnt->next,i++);
            return cnt->date;
        }
        else
            return -1;
    }
    void replaceAt(T NewElement , int index)
    {
        if(index < length)
        {
            int i = 0;
            node<T> *cnt = head;
            for (; i <= index; cnt = cnt->next, i++);
            cnt->date = NewElement;
        }
    }
    bool isExist (T element)
    {
        int i = 0;
        node<T> *cnt = head;
        for (; i < length; cnt = cnt->next, i++)
            if(cnt->date == element)
                return 1;
        return 0;

    }
    bool isItemAtEqual(T Element , int index)
    {
        return (Element == retrieveAt(index));
    }
    void print ()
    {
        node <T> *tmp;
        tmp = head;
        for(int i = 0 ; i < length ; i++)
        {
            cout << tmp->date << " ";
            tmp = tmp -> next;
        }
        cout << endl;
    }
    void insertAt(T element , int index )
    {
        if(index == 0)
            insertAtHead(element);
        else if(index == length-1 or isEmpty())
            insertAtEnd(element);
        else
        {
            node <T> *tmp ; tmp = new node<T>(element);
            int i = 1 ;
            node<T> *cnt = head;
            for( ;i < index ; cnt = cnt->next,i++);
            tmp->next = cnt->next ;
            cnt->next = tmp ;
            length++;
        }
    }
    void Swap(int index1 , int index2)
    {
        int i = 0;
        node<T> *cnt = head;
        for (; i < index1; cnt = cnt->next, i++);
         i = 0;
        node<T> *cnt2 = head;
        for (; i < index2; cnt2 = cnt2->next, i++);
        swap(cnt->date,cnt2->date);
    }
    int size()
    {
        return length;
    }
    void clear()
    {
        length = 0 ;
    }
};


int main ()
{
    
    Circular_Linked_List<int> list;
    cout << "\ninsertAtEnd 3 4 5 6 7 \n";
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.print();
    cout << "\ninsertAtHead 2 1 \n";
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.print();
    cout << "\nremoveAtHead \n";
    list.removeAtHead();
    list.print();
    cout << "\nremoveAtEnd \n";
    list.removeAtEnd();
    list.print();
    cout << "\nremoveAt 1 \n";
    list.removeAt(1);
    list.print();
    cout << "\nreplaceAt index 3 => 0 \n";
    list.replaceAt(0 , 2);
    list.print();
    cout << "\nswap 2,4 \n";
    list.Swap(1,3);
    list.print();

}