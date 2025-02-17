#include <iostream>
#include <vector>
#include "IntArr.h"
#include "ForwardList.h"

int main(){
    ForwardList<int> list;
    
    list.Add(Node<int> {.Data = 15, .Next = nullptr});
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