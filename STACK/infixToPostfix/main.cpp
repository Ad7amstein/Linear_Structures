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
    bool isEmpty(){return (size==0) ;}

};

int operators(char c){
    if (c == '+' || c == '-')
        return 1 ;
    if (c == '*' || c == '/')
        return 2 ;
    if (c == '^')
        return 3 ;
    else if (c =='(' || c ==')')
        return 4;
    return 0 ;

}

int main()
{
    stack<char>st ;
    string s ;
    getline(cin ,s ) ;
    string ans ;
    int num = 0 ;
    for(int i =0 ;i<s.size() ;i++){
        char c = s[i] ;
        if (c==')'){
            while(st.top()!= '('){
                ans+=st.pop() ;
            }
            st.pop();
            continue;
        }
        if (!operators(c)){
            ans+= c ;
            if (c!=' ')
                num++ ;
        }
        else{
            int v = operators(c)  ;
            while (!st.isEmpty() && v <= operators(st.top()) && st.top() != '(' ){
                ans+=st.top() ;
                st.pop();
            }
            st.push(c) ;
        }
    }
    while(!st.isEmpty()){
        ans+=st.pop() ;
    }
    cout<<ans<<endl;
    return 0;
}
