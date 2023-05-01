#include<bits/stdc++.h>
using namespace std;
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
        arr = new T[Size];
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
        T tmp ;
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
void printBinaryIntegers(int n)
{
    Queue<string> q(100); // assuming maximum size of 100
    q.enqueue("1"); // enqueue the first binary integer

    for (int i = 0; i < n; i++) // repeat n times
    {
        string curr = q.dequeue(); // dequeue the current binary integer
        cout << curr << " "; // print it

        string next = curr; // create the next binary integer by appending '0' and '1'
        q.enqueue(next.append("0"));
        q.enqueue(curr.append("1"));
    }
}
int main()
{
    cout << "\n If the Input is: 3 \n";
             printBinaryIntegers(3);
    cout << "\nIf the Input is: 5 \n";
             printBinaryIntegers(5);
}
