/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include "xy_vector.cpp"
using namespace std;


int main(){


      // entering an array to vector
      int arr[5] = {8,9,10,11,12};
      xyVector<int> array(arr,5);

      
      // pushing back items
      xyVector<int> v;
      v.push_back(4);
      v.push_back(5);
      v.push_back(6);
      v.push_back(7);
      v.push_back(8);
      v.push_back(9);
      v.push_back(10);
      v.push_back(11);
      v.push_back(12);
     

      cout << "iterating with iterators : \n";
      xyVector<int>::iterator iter = v.begin();
      for(iter = v.begin(); iter != v.end() ; iter++){
            cout << *iter << ((iter != v.end() - 1) ? "," : "");
            
      }
      cout << '\n';


      cout << "erase the iterator erase(v.begin() + 1) : ";
      v.erase(v.begin() + 1);
      for(int i = 0; i  != v.size() ; i++){
            cout << v[i] << (( i != v.size() - 1) ? "," : "");
          
      }
      cout << '\n'; 


      cout << "erase(v.begin(),v.begin() + 2)) : ";
      v.erase(v.begin(),v.begin() + 2);
      for(int i = 0; i  != v.size() ; i++){
            cout << v[i] << (( i != v.size() - 1) ? "," : "");
          
      }
      cout << '\n';
      
      cout << "printing the vector with << operator : ";
      cout << v << '\n';
    
      cout << "comparing with == operator (v == array) : ";
      cout << (v == array) << '\n';

      cout << "resizing to 20 elements : ";
      v.resize(20);
      cout << v << '\n';

      cout << "insert(v.begin(),7) : ";
      v.insert(v.begin(),7);
      cout << v << '\n';




      return 0;
}
