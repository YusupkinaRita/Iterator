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
    
    // ForwardList(const ForwardList tmp);
    // ForwardList& operator=(const ForwardList& p);
    void Add(Node<T> node){
        ListIterator<T> lit = ListIterator<T>(_head);

        while((*lit).Next!=nullptr){
            lit++;
        }

        (*lit).Next=&node;
    }


    ListIterator<T> begin(){
        return ListIterator<T> (_head);
    }
    ListIterator<T> end(){
        return ListIterator<T>(_tail->Next);

    }
    void Delete(Node<T> node){
        
    }
    bool Contains(Node<T> node){
        for (ListIterator<T> lit:*this){
            if(lit._node->Data==node.Data)
            return true;
        }
        return false;
    }




};