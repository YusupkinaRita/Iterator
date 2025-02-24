#include <iostream>

template<class T>
struct Node{
    T Data;
    Node* Next=nullptr;

   
    
};

template<class T>
struct ListIterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Node<T>;
    using pointer= Node<T>*;
    using reference = Node<T>&;
    ListIterator(pointer node):_node(node){};
    reference operator*()const{return *_node;};
    pointer operator->(){return _node;};
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
    void SetNext(Node<T>* next){
        _node->Next=next;
    }
private:
    pointer _node;
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
    
    void Add(Node<T> node){
        if(_head!=nullptr){
            ListIterator<T> lit = begin();

            while((*lit).Next!=nullptr){
                lit++;
            }

            (*lit).Next=&node;
            _tail=&node;
        }
        else{
            _head=&node;
            _tail=&node;

        }
    }


    ListIterator<T> begin(){
        return ListIterator<T> (_head);
    }
    ListIterator<T> end(){
        return ListIterator<T>(_tail->Next);

    }
    void Delete(T data){
            ListIterator<T> lit = ListIterator<T>(_head);
            Node<T> tmp1;
            if(*(_head).Data==data)
                _head=nullptr;

            while((*lit).Next!=nullptr){
                if(*((*lit).Next)==data){
                    tmp1=*lit;
                    break;
                }
                lit++;
            }
            if((tmp1.Next)->Next!=nullptr){
                Node<T> tmp2=*(*(tmp1.Next)->Next);
                tmp1.Next=&tmp2;
            }
            else
                tmp1.Next=nullptr;



        
        
    }
    bool Contains(T data){
        for(auto lit=begin();lit!=end();lit++){
            T x=(*lit).Data;
            if(x==data)
                return true;
            lit++;
        }
        return false;
    }
    

    friend std::ostream& operator<<(std::ostream& os, const ForwardList& l){
        ListIterator<T> lit = ListIterator<T>(l._head);

        while(lit!=nullptr){
            os<<lit._node->Data<<" ";
        
            lit++;
        }
        std::cout<<std::endl;
            
        
        return os;
    }




};