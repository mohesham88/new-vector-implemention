#include "xy_vector.h"


// defautl constructor
template<class T>
xyVector<T>::xyVector(){
        this->capacity = 2;
        sz = 0;
        data = new T [capacity];
}


template<class T>
xyVector<T>::xyVector(int cap){
        this->capacity = cap;
        sz = 0;
        data = new T [capacity];
}


// Initialize by n items from array 
template<class T>
xyVector<T>::xyVector(T* dt, int n){
    
    
    data = new T[n];
    sz = n;
    capacity = n;


    for(int i = 0;i < n;i++){
        data[i] = dt[i];
    }


}
// destructor 
template<class T>
xyVector<T>::~xyVector(){
    delete [] data;
}

template<class T>
T& xyVector<T>::operator[](int idx){
    try{
        if(idx > sz - 1){
            throw outOfRange(idx);
        }
    }
    catch( xyVector<T>::outOfRange e){
        cout << e.get_idx()  << " is out of range";
        
    }
    
    return data[idx];
    
    
}

template<class T>
ostream& operator << (ostream& out, xyVector<T> v){

    for(int i = 0; i < v.size();i++){
        out << ((i == 0) ? "[" : "")  << v[i] << ((i != v.size() - 1) ? "," : "]");
    }

    return out;
} 

// copy constructor
template<class T>
xyVector<T>::xyVector(const xyVector<T>& another_vec){
    capacity = another_vec.capacity;
    sz = another_vec.sz;

    data = new T[sz];

    for(int i = 0 ;i < sz;i++){
        data[i] = another_vec.data[i];
    }

}


// copy assignment operator = 
template<class T>
xyVector<T>& xyVector<T>::operator =(const xyVector<T>& another_vec){
    capacity = another_vec.capacity;
    sz = another_vec.sz;

    data = new T[sz];

    for(int i = 0 ;i < sz;i++){
        data[i] = another_vec.data[i];
    }
    return *this;
}

// move assignment opeartor = 
template<class T>
xyVector<T>& xyVector<T>::operator =(const xyVector<T>&& another_vec){
    // if they are not the same
    if(this != &another_vec){
        delete [] data;
        sz = another_vec.sz;
        capacity = another_vec.capacity;
        data = another_vec.data; 

        another_vec.sz = 0;
        another_vec.capacity = 0;
        another_vec.data = nullptr;


    }
    return *this;

}

template<class T>
int xyVector<T>::push_back(T item){

    if(capacity > sz){
        data[sz++] = item;
    }

    else{
        capacity *= 2;
        T* new_data = new T[capacity];
        for(int  i = 0 ; i < sz;i++){
            new_data[i] = data[i];
        }
        new_data[sz] = item;
        sz++;
        delete [] data;
        data = new_data;
        new_data = nullptr;
    }




    return sz;
}

template<class T>
T xyVector<T>::pop_back(){

    T back = data[sz - 1];
    if(sz > 0){
        // call the last item destructor
        data[sz - 1].~T();    
        sz--;
    }
    return back;
    

} 

template<class T>
int xyVector<T>::size() const{
    return sz;
}

template<class T>
int xyVector<T>::Capacity() const{
    return capacity;
} 
template<class T>
bool xyVector<T>::empty(){
    return (size == 0);
} 


template<class T>
void xyVector<T>::resize(int new_size) {

    if(new_size == 0){
        delete [] data;
        sz = 0;
        data = new T[0];
        capacity = 2;
        return;
    }

    // if current size is bigger
    if(new_size < sz){
        T* new_data = new T[new_size];
        
        for(int i = 0 ; i < new_size;i++){
            new_data[i] = data[i];
        }

        delete [] data;
        sz = new_size;
        capacity = new_size;
        data = new T[sz];

        for(int i = 0 ; i < sz;i++){
            data[i] = new_data[i];
        }

        delete [] new_data;

    }

    else if (new_size > sz){
        T* new_data = new T[new_size];
        
        for(int i = 0 ; i < sz;i++){
            new_data[i] = data[i];
        }
        // add the remaining elemets
        for(int i = sz; i < new_size;i++){
            new_data[i] = T();
        }

        delete [] data;
        sz = new_size;
        capacity = new_size;
        data = new T[sz];

        for(int i = 0 ; i < sz;i++){
            data[i] = new_data[i];
        }

        delete [] new_data;

    }

} 

template<class T>
void xyVector<T>::clear(){
    // call every element destructor
    for(int i = 0 ; i < sz;i++){
        data[i].~T();
    }
    sz = 0;
}

template<class T>
void xyVector<T>::erase(xyVector<T>::iterator iter){
    


    try{

        if(!(iter >= begin() && iter < end())){
            throw outOfRange();
        }

        T* new_data = new T[sz - 1];

        int idx = 0;


        for(iterator it = begin(); it != end();it++){
            if(it == iter){
                continue;
            }
            new_data[idx] = *it;
            idx++;
        }

        delete [] data;
        sz--;
        data = new T[sz];

        for(int i = 0 ; i < sz;i++){
            data[i] = new_data[i];
        }


        delete [] new_data;
    }
    catch(outOfRange){
        cout << "iterator is out_of_range \n";
    }


} 




template<class T>
void xyVector<T>::erase(xyVector<T>::iterator iter1 ,xyVector<T>::iterator iter2){
    try{
        // if iter1 <= iter2 else do nothing 
        if(iter1 <= iter2 && (iter1 >= begin() && iter1 < end()) && (iter2 >= begin() && iter2 < end())){
              T* new_data = new T[sz - 1];

            int idx = 0;


            for(iterator it = begin(); it != end();++it){
                // skip the range between iter1 and iter2
                if( it >= iter1 && it <= iter2 ){
                    continue;
                }

                new_data[idx] = *it;
                idx++;

            }

            delete [] data;

            sz = idx;
            data = new T[sz];

            for(int i = 0 ; i < sz;i++){
                data[i] = new_data[i];
            }


            delete [] new_data;

        
        }
        else{
            throw outOfRange();
        }
    }
    catch(outOfRange){
        cout << "iterators are out of range\n";
    }


} 
 

template<class T>
bool xyVector<T>::operator==(xyVector<T>& v){

    if(sz == v.size()){
        for(int i = 0; i < sz ;i++){
            if( data[i] != v[i]){
                return false;
            }
        }

        return true;
    }
    else
        return false;
}


template<class T>
bool xyVector<T>::operator< (xyVector<T>& v){

    for(int i = 0; i < min(sz,v.size()) ;i++){
        
        if(data[i] < v[i]){
            return true;
        }
        else if(data[i] > v[i]){
            return false;
        }

    }
    return false;

}

template<class T>
bool xyVector<T>::operator> (xyVector<T>& v){
    for(int i = 0; i < min(sz,v.size()) ;i++){
        if(data[i] > v[i]){
            return true;
        }
        else if(data[i] < v[i]){
            return false;
        }
    }
    return false;

}

template<class T>
void xyVector<T>::insert(iterator iter , T element){
     try{

        if(!(iter >= begin() && iter <= end())){
            throw outOfRange();
        }
        // sz + 1 because we add one more element
        T* new_data = new T[sz + 1];
        
        int idx = 0;
        for(iterator it = begin(); it != end() + 1;it++){
            if(it == iter){
                new_data[idx++] = element;
            }
            if(it != end()){
                new_data[idx] = *it;
                idx++;
            }
        }

     
        delete [] data;
        sz++;
        if(sz > capacity){
            capacity *=2;
        }
        data = new T[sz];

        for(int i = 0 ; i < sz;i++){
            data[i] = new_data[i];
        }
        delete [] new_data;
    }
    catch(outOfRange){
        cout << "iterator is out_of_range \n";
    }
}