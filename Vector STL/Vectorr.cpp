
#include <cassert>
#include <iostream>

template <typename T>
    
class Vectorr{
public:
    class Iterator{
    public:
        Iterator(T* ptr){ 
             I_ptr=ptr; 
        }
        bool operator!=(const Iterator& rside){
            return (rside.I_ptr==this->I_ptr)? false:true;
        }
        Iterator operator++(){
            Iterator i = *this;
            I_ptr++;
            return i;
        }
        T& operator*(){
            return *I_ptr;
        }
    private:
        T* I_ptr;
    };
   
   /*Default constructor*/
   Vectorr();
    
   /*Fill constructor*/
   Vectorr(const int size);  

   /*Copy constructor*/
   Vectorr(const Vectorr& rside);   
   
   /*Destructor */
   ~Vectorr();
 
   /*Overloaded asigment operator*/
   Vectorr& operator=(const Vectorr& rside);
   
   //overloaded [] operator for only read
   const T& operator[](const  int index) const;
    
    //overloaded [] operator for  read and write
    T& operator[](const  int index);
   // new_Capacity Function
   
    void new_Capacity();
   
   // Push_Back Function
   void push_back(T&& n);
    
    // Size Function
    T size() const;
    
    // Capacity Function
    T capacity() const;
    
   /*Iterator begin*/
    T* begin(){
        return V_arr;
    }


    /*Iterator end*/
    T* end(){
        return V_arr+V_size;
    }
   
private:
   unsigned int V_size;
   unsigned int V_Capacity;
   T* V_arr;   
};



    
/*Default constructor*/
template <typename T >
Vectorr<T>::Vectorr(){
    V_Capacity = 2;
    V_arr = new T [V_Capacity];
    V_size = 0; 
}


/*Fill constructor*/
template <typename T >
Vectorr<T>::Vectorr(const int size){
    V_Capacity=size;
    V_arr = new T[V_Capacity];
    V_size = 0; 
} 
   

/*Copy constructor*/
 template <typename T >
Vectorr<T>::Vectorr(const Vectorr& rside){
    this->V_size=rside.V_size;
    this->V_Capacity=V_Capacity;
    this->V_arr = new T [V_size];
    for(unsigned int i = 0; i < this->V_size; ++i)
    {
     this->V_arr[i] = rside.V_arr[i];
    } 
}    
  
/*overloaded asigment operator*/
template <typename T >
Vectorr<T>& Vectorr<T>::operator=(const Vectorr& rside){
    if(this==&rside)
    {
     return *this;
    }   
    delete [] this->V_arr;
    this->V_Capacity=V_Capacity;
    this->V_size=rside.V_size;
    this->V_arr = new T [V_size];
    for(unsigned int i = 0; i < this->V_size; ++i)
    {
     this->V_arr[i] = rside.V_arr[i];
    } 
    return *this;
}


//overloaded [] operator for only read
template <typename T >
const T& Vectorr<T>::operator[](const  int index) const{
    if(index<0){
        throw index;
    }
    return V_arr[index];
}


//overloaded [] operator for  read and write
template <typename T >
T& Vectorr<T>::operator[](const int index) {
    if(index<0 ){
        throw index;
    }
    return V_arr[index];
} 

// new_Capacity Function
template <typename T >
void Vectorr<T>::new_Capacity(){
    V_Capacity = V_size * 2;
    T* temp = new T[V_Capacity];
    for(unsigned int i = 0; i < V_size; i++)
    {
        temp[i] = V_arr[i];
    }
    delete [] V_arr;
    V_arr = temp;
}

// Push_Back Function
template <typename T >
void Vectorr<T>::push_back(T&& n){
    if(V_Capacity < V_size+1)
    {
        new_Capacity();
    }
    V_arr[V_size] = n;
    V_size++;
}




/*Destructor */
template <typename T >
Vectorr<T>::~Vectorr(){
    if ( V_arr != nullptr)
    {
    delete [] V_arr;
    V_arr=nullptr;
    std::cout<< "i am deleted"<<std::endl;
    }
}  

/*return size */
template <typename T >
T Vectorr<T>::size() const{
    return V_size;
}

// return Capacity Function
template <typename T >
T Vectorr<T>::capacity() const{
    return V_Capacity;
}
