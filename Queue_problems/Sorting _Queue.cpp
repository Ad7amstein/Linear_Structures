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
    void sortQueue()
    {
       vector<T>v;
       int n = size;
        while (n--)
            v.push_back(dequeue());
        sort(v.begin(),v.end());
        n = size;
        int i = 0 ;
        while (n--)
            enqueue(v[i++]);

    }

};


int main()
{
    
    Queue<int>q1(5);
    q1.enqueue(3);
    q1.enqueue(15);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.enqueue(4);
    q1.sortQueue();
    q1.print();




}