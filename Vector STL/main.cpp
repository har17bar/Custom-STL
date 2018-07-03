#include <stdio.h>
#include <iostream>

#include "Vectorr.cpp"

int main(){

   Vectorr<int> myvec(5);
   myvec.push_back(12);
   myvec.push_back(14);
   myvec.push_back(99.9);
   myvec.push_back(19);
   try{
        myvec[500]=7000;
    }
    catch(const int ex){
        std::cout<<"index:"<<ex<<std::endl;
        exit(1);
    }
   
   myvec.push_back(22);
    myvec[2]=7000;
   myvec.push_back(22);
  
   //std::cout<<myvec.capacity()<<std::endl;
  for(Vectorr<int>::Iterator it =myvec.begin(); it!=myvec.end();++it ){
        std::cout<<*it<<std::endl;
    }
    
   //std::cout<<a<<std::endl;
   //Vectorr<int> newvec(myvec);
  // newvec=myvec;
   return 0;
}
