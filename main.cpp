#include <iostream>
#include <vector>
#include "IntArr.h"

int main(){
    IntArr int_ar;
    for(Iterator i=int_ar.begin();i!=int_ar.end();i++){
        *i=0;
        std::cout<<*i<<std::endl;
    }
    // for (auto it:int_ar){
    //     std::cout<<it<<std::endl;
    // }
        
    
}