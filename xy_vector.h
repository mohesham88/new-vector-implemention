/**
 * @file main.cpp
 * @author Mohamed Hesham Mohamed | Mohamed Atef Zaki (you@domain.com)
 * @brief vector implemention
 * @version 0.3
 * @date 2022-12-20
 * 
 * @copyright Copyright FCAI (c) 2022
 * 
 */
#ifndef XYVECTOR
#define XYVECTOR
#include<bits/stdc++.h>
using namespace std;


/**
 * @brief the main class Vector header
 * 
 * @tparam T template to know the vector stored data type 
 */
template<class T>
class xyVector{
private:
    T* data;
    int  sz,capacity;
public:
 
    /**
     * @brief default constructor to init the vector with capacity of 1 and size = 0
     * 
     */
    xyVector();
    /**
     * @brief Construct a new xy Vector with the constructor
     * 
     * @param cap to en
     */
    xyVector(int cap);
    /**
     * @brief Construct a new xy Vector object
     * 
     * @param  n enters the size of the vector
     */
    xyVector(T*,int n);
    /**
     * @brief Destroy the xy Vector object
     * 
     */
    ~xyVector();
    /**
     * @brief copy vector with the constructor
     * 
     */
    xyVector (const xyVector&);
    /**
     * @brief copy vector with the assignment operator
     * 
     * @return xyVector& the vector with the copied data
     */
    xyVector &operator =(const xyVector&); // copy assignment
    /**
     * @brief move the data from object to anther
     * 
     * @return xyVector& the vector with new data 
     */
    xyVector &operator =(const xyVector&&);  // move assignment
    /**
     * @brief push back an element of data type T to the vector
     * 
     * @return int the element that was pushed
     */
    int push_back(T);
    /**
     * @brief delete the last element from the vector
     * 
     * @return T the item that was deleted
     */
    T pop_back();  
    /**
     * @brief get the vector size
     * 
     * @return int the size of the vector
     */
    int size() const;
    /**
     * @brief access the vector elements using the [] operator 
     * 
     * @return T& the item with the index entered
     */
    T& operator[] (int);
    /**
     * @brief get the capacity of the vector
     * 
     * @return int the capacity of the vector(object)
     */
    int Capacity() const;
    /**
     * @brief check if the vector is empty or not
     * 
     * @return true if the vector is  empty
     * @return false it vector is not empty
     */
    bool empty();
    /**
     * @brief fucntion that prints the vector element using << operator
     * 
     * @tparam t the data type of the vector
     * @param out ostream operator 
     * @param v the vector itself
     * @return ostream& the output stream operator
     */
    template<class t>
    friend ostream& operator << (ostream& out, xyVector<t> v);
    /**
     * @brief checks if two vectors are equal
     * 
     * @return true if the two vectors are equal
     * @return false if the two vectors are not equal
     */
    bool operator==( xyVector<T>&); // Return true if ==  
    /**
     * @brief compares two vectors by elements > 
     * 
     * @return true if the first element that differs in the two vectors in the first vector is bigger > than in the second
     * @return false if the first element that differs in the two vectors in the first vector is smaller < than in the second
     */
    bool operator< ( xyVector<T>&); // Compares item by item
    /**
     * @brief compares two vectors by elements <
     * 
     * @return true if the first element that differs in the two vectors in the first vector is smaller < than in the second
     * @return false true if the first element that differs in the two vectors in the first vector is bigger > than in the second
     */
    bool operator> ( xyVector<T>&); // Compares item by item
    /**
     * @brief takes the new size as a parameter and changes teh size of the vector the new size
     * 
     */
    void resize(int);


 

    /**
     * @brief vector iterator class to iterate through the vector
     * 
     */
    class iterator{
        T* ptr;
    public:
        iterator(){
            ptr = nullptr;
        }

        iterator(T* pointer){
            ptr = pointer;
        }


        bool operator!=(iterator another_iterator){
            return (ptr != another_iterator.ptr);
        }   

        T operator*(){
            return *ptr;
        }


        // overloading the ++ operator
        // prefix iter++;
        void operator ++ (){
            ptr++;
        }
        // postfix ++iter
        iterator operator ++ (int){
            iterator old = *this;
            ptr++;
            return old;
        }

        iterator operator+(int a){
            return iterator(ptr + a);
        }

        iterator operator-(int a){
            return iterator(ptr-+ a);
        }

        iterator operator+(iterator it){
            return iterator(ptr + it.ptr);
        }
        iterator operator-(iterator it){
            return iterator(ptr - it.ptr);
        }


        bool operator<(iterator it){
            return (ptr < it.ptr);
        }
        bool operator>(iterator it){
            return (ptr > it.ptr);
        }
        bool operator<=(iterator it){
            return (ptr <= it.ptr);
        }
        bool operator>=(iterator it){
            return (ptr >= it.ptr);
        }
        bool operator==(iterator it){
            return (ptr == it.ptr);
        }



    };
    

    iterator begin(){
        return iterator(data);
    }
    iterator end(){
        return iterator(data + sz);
    }
    /**
     * @brief clear the vector
     * 
     */
    void clear();
    /**
     * @brief takes an iterator and deletes  it
     * 
     */
    void erase(iterator);
    /**
     * @brief deletes the elements from iterator 1 to iterator 2
     * 
     * @param iter1 the first iteratror 
     * @param iter2 the second iterator
     */
    void erase(iterator iter1,iterator iter2);
    /**
     * @brief insert a new element at the iterator position
     * 
     * @param iter the position in which the element will be put on
     * @param element the element to be inserted
     */
    void insert(iterator iter, T element);       // Insert item at iterator 


    
    
    
    
    
    
    
    
    
    
    
    /**
     * @brief out of range class used as exception
     * 
     */
    class outOfRange{
        int idx;
        public:
        outOfRange(){}
        outOfRange(int i):idx(i){}
        int get_idx(){return idx;}
    };


};



#endif