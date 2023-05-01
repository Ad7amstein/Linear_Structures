#include <iostream>

using namespace std;

template<typename T>
class Array{
    T* ptr  ;
    int mxsize ;
    int size ;
public:
    Array(int a ){
        ptr = new T(a);
        size = 0 ,mxsize =a ;
    }
    ~Array(){
        delete[]ptr ;
    }
    void insert(T elm){
        if (size == mxsize){
            cout<<"the Array is empty\n";
            return ;
        }
        ptr[size] = elm ;
    }
    void insertAt(T elm ,int idx) {
        if (size == mxsize){
            cout<<"the Array is empty\n";
            return ;
        }
        if (idx>= size || idx<0){
            cout<<"INVALID index\n";
            return ;
        }
        for(int i = size-1 ; i> = idx ; i-- ){
            ptr[i+1] = ptr[i] ;
        }
        ptr[idx] = elm ;
    }
    bool isEmpty (){ return (size == 0) ;}
    bool isFull () { return (size == mxsize) ;}
    int listSize (){ return size ;}
    int maxListSize (){return mxsize ;}
    void clear (){ delete[] ptr ; size =0 , mxsize =0 ;}
    void print(){
        for(int i =0 ;i< size ;i++)
            cout<<ptr[i] ;
    }

    void removeAt (int idx) {
        if (idx >= size || idx <0){
            cout<<"INVALID INDEX\n";
            return ;
        }
        for(int i = idx  ;i<size -1 ;i++){
            ptr[i] = ptr[i+1] ;
        }
        size--;
    }
    void replaceAt ( T newElement, int idx){
         if (idx >= size || idx <0){
            cout<<"INVALID INDEX\n";
            return ;
        }
        ptr[idx] = newElement ;
    }
    bool isItemAtEqual ( T elm, int idx) {
        if (idx >= size || idx<0){
            cout<<"invalid index \n" ;
            return 0 ;
        }
        return elm == ptr[idx] ;
    }

    T retrieveAt (int idx){
        if (idx >= size || idx<0){
            cout<<"invalid index \n" ;
            return 0 ;
        }
        return ptr[idx] ;
    }
};

int main()
{

    return 0;
}
