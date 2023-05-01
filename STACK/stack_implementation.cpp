#include <iostream>

using namespace std;

template <typename T>
class stack{
private:
    struct node{
        T data ;
        node* nxt ;
    };
    node* head ;
    int size  = 0;
public:
    stack(){
        head = nullptr ;
        size = 0 ;
    }
    ~stack(){
        clear() ;
    }
    void push(T elm ){
        node * newnode = new node() ;
        newnode->nxt = head ;
        newnode->data = elm ;
        head = newnode ;
        size++;
    }
    T pop(){
        try{
            if (head== nullptr)
                throw(2) ;
            node* lastode =  head ;
            head = head->nxt ;
            T x = lastode->data ;
            delete lastode ;
            size--;
            return x ;
        }
        catch( int x){
            cout<<"can't pop, the stack is empty\n" ;
            return NULL ;
        }

    }
    T top(){
        try{
            if (head == nullptr)
                throw (2);
            return head->data ;
        }
        catch (int x){
            cout<<"there is no top, the stack is empty\n" ;
            return NULL ;
        }
    }
    void clear(){
        node* cur = new node() ;
        while(head != nullptr) {
            delete cur;
            cur = head;
            head = head->nxt;
        }
        size = 0 ;
    }
    void print(){
        node* cur = new node() ;
        cur = head ;
        while(cur!= nullptr){
            cout<<cur->data<<" ";
            cur =cur->nxt ;
        }
    }
    int stackSize(){return size ;}
    bool isEmpty(){return bool(size) ;}

};


int main()
{
    cout << "Hello world!" << endl ;
    stack<int>st ;
    cout<<st.stackSize()<<endl ;
    st.push(5) ;
    cout<<st.top()<<endl;
    st.push(12) ;
    st.push(1) ;
    for (int i = 1; i < 6; ++i) {
        st.push(i)  ;
    }
    cout<<st.stackSize()<<endl ;
    cout<<st.pop() ;
    cout<<st.top()<<endl  ;
    st.print() ;
    st.push(-1) ;
    cout<<st.top()<<endl ;
    cout<<st.isEmpty()<<st.stackSize()<<endl ;
    st.clear() ;
    cout<<st.top()<<endl ;
    cout<<st.isEmpty()<<st.stackSize()<<endl ;
    return 0;
}
