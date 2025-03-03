#include <iostream>
#include <algorithm>

template<class T>
struct Node{
    T Data;
    Node* Next=nullptr;
    Node(T data) {
        Data = data;
    }
    Node(){

    }

   
    
};

template<class T>
struct ListIterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer= T*;
    using reference = T&;
    ListIterator(Node<T>* node):_node(node){};
    reference operator*()const{return _node->Data;};
    pointer operator->(){return &(_node->Data);};
    ListIterator<T> operator++(int){
        ListIterator<T> tmp=*this;
        ++(*this);
        return tmp;
    };
    ListIterator<T>& operator++(){

        _node=_node->Next;
        return *this;
    }
    friend bool operator==(const ListIterator& a,const ListIterator& b){
        return a._node==b._node;
    }
    friend bool operator!=(const ListIterator& a,const ListIterator& b){
        return a._node!=b._node;
    }
private:
    Node<T>* _node;
};

template<class T>
class ForwardList{
private:
    Node<T>* _head ;
    Node<T>* _tail;
public:
    ForwardList(){
        _head=nullptr;
        _tail=nullptr;
    }
    
    void Add(T data) {
        if (_head == nullptr) {
            _head = new Node<T>(data);
            _tail = _head;
        } else {
            _tail->Next = new Node<T>(data);
            _tail = _tail->Next;
        }
    }


    ListIterator<T> begin(){
        return ListIterator<T> (_head);
    }
    ListIterator<T> end(){
        return ListIterator<T>(_tail->Next);

    }
    // void Delete(T data){
    //     Node<T>* tmp1;
    //     bool delnum_ishere=0;
    //     if((*_head).Data==data){
    //         _head=nullptr;
    //     }
    //     else{
    //         Node<T>* prev;
    //         for(auto lit=begin();lit!=end();lit++){
    //             if(lit == begin())
    //                 prev=&(*lit);
    //             else{
    //                 T x=(*lit).Data;
    //                 if(x==data){
    //                     delnum_ishere=true;
    //                     tmp1=prev;
    //                     break;
    //                 }
    //                 prev=&(*lit);
    //             }      
    //         }

    //         if(delnum_ishere){
    //             if((tmp1->Next)->Next!=nullptr){
    //                 Node<T>* tmp2=(tmp1->Next)->Next;
    //                 tmp1->Next=tmp2;
    //             }
    //             else
    //                 tmp1->Next=nullptr;
    //             }
            
    //         else
    //             std::cout<<"the object you want to delete is not in the queue"<<std::endl;

    //     }

    // }
    void Delete(T data){
        

    }
    bool Contains(T data){
        for(auto lit=begin();lit!=end();lit++){
            T x=(*lit).Data;
            if(x==data)
                return true;
        }
        return false;
    }
    

    friend std::ostream& operator<<(std::ostream& os, ForwardList& l){
        ListIterator<T> lit = ListIterator<T>(l._head);

        for (auto f : l){
            std::cout<<f<<" ";
        }
        // while(lit!=nullptr){
        //     os<<(*lit).Data<<" ";
        
        //     lit++;
        // }
            
        
        return os;
    }




};