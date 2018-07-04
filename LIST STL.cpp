#include <iostream>



template <typename T>
class List{
  
public:
    List(){
        L_count = 0 ;
        L_first = nullptr;
       
    }
    
    ~List(){
        
    }
    int getSize(){return L_count;}
    void push_back(T pdata){
        if(L_first==nullptr){
            L_first=new Node<T>(pdata);
        }
        else{
            Node<T> *current  = L_first;
            while(current->N_pNext!=nullptr){
                current=current->N_pNext;
            }
            current->N_pNext=new Node<T>(pdata);
        }
        ++L_count;
    }
    
    T& operator[](const int index){
        int counter = 0 ; 
        Node<T> *curent = L_first;
       while(curent!=nullptr){
           if(counter==index)
               return curent->N_data;
           curent= curent->N_pNext;
           counter++;
        }
    }
private:

    template <typename List> class Node{
    public:
        Node *N_pNext;
        T N_data;
        
        Node(T data=T(), Node *pNext=nullptr){
            this->N_data=data;
            this->N_pNext=pNext;
        }
    };
    int L_count;
    Node<T> *L_first;
   
};
int main(){
    
    List<int> lst;
    lst.push_back(17);
    lst.push_back(10);
    lst.push_back(88);
    lst.push_back(100);
    for(int i = 0 ; i<lst.getSize(); ++i ){
        std::cout<<lst[i]<<std::endl;
    }
}