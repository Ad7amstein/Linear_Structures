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
        return added_element;
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

template<typename T>
class Stack {
private:
    Queue<T> *q1;
    Queue<T> *q2;
public:
    Stack(int n)
    {
        q1 = new Queue<T>(n);
        q2 = new Queue<T>(n);
    }
    void push(T element)
    {
        q1->enqueue(element);
    }
    T pop() {
        int n = q1->queueSize();
        for (int i = 0; i < n - 1; i++) {
            q2->enqueue(q1->dequeue());
        }
        T poppedElement = q1->dequeue();
        swap(q1, q2);
        return poppedElement;
    }

};

int main()
{
    Stack<int>st(4);
    cout << "\npush 1 2 3 4 \n";
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "\npop first element \n \n" ;
   cout << st.pop() << endl;
   cout << "\npop second element \n \n" ;
   cout << st.pop() << endl;
   cout << "\npop third element \n \n" ;
   cout << st.pop() << endl;
}