#include <iostream>
template<typename T>
class List{
public:
    List(){
        size = 0;
        head= nullptr;
    }
    ~List(){
        clear();
    }
    void clear(){
        while (size)
        {
            pop_Front();
        }
        std::cout<<"List is empty"<<std::endl;
    }
    void pop_Front(){
        if(size==0)
        {
            std::cout<<"List is empty"<<std::endl;
            return;
        }
        Node<T>* tmp = head;
        head=head->next;
        delete tmp;
        --size;
    }
    void insert_at(T value , int index){
        
        Node<T>* previus = head;
        for(int i=0;i<index-1; ++i){
            previus=previus->next;
        }
        
    }
    void push_front(T pdata){
         Node<T>* head = new Node<T>(pdata,head);
         ++size;
    }
   
    void push_back(T pdata){
        if(head==nullptr)
        {
            head=new Node<T>(pdata);
        }
        else
        {
            Node<T> *current  = head;
            while(current->next!=nullptr){
                current=current->next;
            }
            current->next=new Node<T>(pdata);
        }
        ++size;
    }
    int getsize(){return size;}
    T& operator[](int index){
        int counter = 0 ;
        Node<T> *current  = head;
        while(current!=nullptr){
            if(counter==index)
            {
                return current->data;
            }
            current= current->next;
            counter++;
        }
        return current->data;
    }
    template<typename List>class Node{
    public:
        Node(T dataa , Node* nextt=nullptr)
        {
            this->data=dataa;
            this->next=nextt;
        }
        T data;
        Node* next;
    };
private:
    Node<T>* head;
    int size;
};
int main(){
    List<int> lst;
    lst.push_back(18);
     lst.push_back(19);
     lst.push_back(20);
     lst.push_front(700);
     lst.pop_back();
    for(int i = 0 ; i< lst.getsize();++i)
    {
        std::cout<<lst[i]<<std::endl;
    }
    return 0;
}