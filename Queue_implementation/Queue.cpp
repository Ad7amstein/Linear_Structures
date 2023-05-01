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
class Queue
{
    int size;
    int front;
    int rear;
    int added_element;
    T * arr;
public:
    Queue(int Size)
    {
        rear = front = added_element = 0 ;
        size=Size;
        arr = new int[Size];
    }
    
    int next(int pos)
    {
        return ((pos+1) % size);
    }
    bool isFull ()
    {
        return (added_element == size);
    }
    bool isEmpty()
    {
        return (added_element == 0);
    }
    void enqueue(T element)
    {
        if(! isFull())
        arr[rear] = element;
        rear = next(rear);
        added_element++;
    }
    T dequeue()
    {
        int tmp = -1;
        if(!isEmpty())
        {
            tmp = arr[front];
            front = next(front);
            added_element--;
        }
        return tmp;
    }
    T first ()
    {
        return arr[front];
    }
    int queueSize()
    {
        return size;
    }
    void clear()
    {
        size = 0  ;
    }
    void print ()
    {
        for (int i = 0 ,j = front; i < added_element ; i++, j = next(j))
                cout << arr[j] << " " ;
        cout << endl;
    }

};
int main()
{
    Queue<int>q(6);
    cout << "\n enqueue 1 2 3 4 5 \n ";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    cout << "\n dequeue \n ";
    q.dequeue();
    q.print();
    cout << "\n dequeue \n ";
    q.dequeue();
    q.print();



}