#include <iostream>
#include <vector>
#include "IntArr.h"
#include "ForwardList.h"

int main(){
    ForwardList<int> list;
    //Node<int> n{.Data = 15, .Next = nullptr};
    
    for(size_t i=0; i<7;i++){
        list.Add(i);
    }
    std::cout<<list<<std::endl;
    //std::cout<<(list.Contains(3)? "yes":"no")<<std::endl;
    list.Delete(15);
    list.Delete(3);
    std::cout<<list<<std::endl;
    list.Delete(1);
    std::cout<<list<<std::endl;
    //std::cout<<(list.Contains(3)? "yes":"no")<<std::endl;
    //std::cout<<list.Contains(15)<<std::endl;
    //list.Delete(n);
    //std::cout<<list<<std::endl;
    // for(Iterator i=int_ar.begin();i!=int_ar.end();i++){
    //     *i=0;
    //     std::cout<<*i<<std::endl;
    // }
    // for (auto it:int_ar){
    //     std::cout<<it<<std::endl;
    // }
    // for(auto i=int_ar.cbegin();i!=int_ar.cend();i++){
    //     std::cout<<*i<<std::endl;
    // }
        
    
}