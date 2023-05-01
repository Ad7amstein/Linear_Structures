#include <iostream>
#include <map>

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
    bool isEmpty(){return (size==0) ;}

};


int main()
{
    string s ;
    cin>>s ;
    stack<int>st;
    int n = s.size() , lst = 0  , ans= 0 ;
    for(int i=0 ;i<n ;i++){
        if (s[i]=='('){
            if (~lst)
                st.push(lst);
            else
                st.push(i) ;
            lst = -1 ;
        }
        else{
            lst = -1 ;
            if (st.isEmpty())
                continue;
            ans = max( ans , i - (st.top() )+1 ) ;
            lst = st.pop() ;
        }
    }
    cout<<ans ;
    return 0;
}
