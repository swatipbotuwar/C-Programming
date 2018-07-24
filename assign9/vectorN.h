/*****************************************************************
NAME : SWATI BOTUWAR
Z-ID : Z1828087
CSCI/689/Section 1
TA NAME : NITHIN DEVANG
ASSIGNMENT NUMBER :9
DUE DATE : THURSDAY, 4th MAY  2017
DESCRIPTION: This is a header file of template Class VectorN. 
             As a template class, class is implemented entirely 
             in header file.
******************************************************************/


#ifndef VECTORN_H   
#define VECTORN_H

#include <iostream>
#include <vector>
#include <ostream>
#include <cstdlib>
#include<stdlib.h>
#include<array>
using std :: vector;
using std ::cout;
using std :: ostream;
using std :: free;

template<class T>
class VectorN
{
    int n;
    T *array;
    
    int capacity;
       public:
          VectorN(); //default constructor
          VectorN(int);  //Parameterized constructor
          VectorN(const T array[],int); //constructor with two argument
          VectorN(const VectorN& );  //copy constructor
          ~VectorN(); // destructor
          VectorN<T>& operator=(const VectorN<T>&);
          void clear();
          int size() const;
          T operator[](int index) const;
          T& operator[](int index);
          bool operator ==(const VectorN<T>&) const;
          VectorN<T> operator +(const VectorN<T>&) const;
          template <class S>
          friend ostream& operator << (ostream& ostr, const VectorN<S>& );

};


/* class implementation starts here  */


//Default constructor 

template <class T>
VectorN<T> :: VectorN()
{
    array = nullptr;
    n = 0;
}

//constructor with one argument 
 
template <class T>
VectorN<T> :: VectorN(int size)
{
    n = size;
    array = new T[n];
}

//constructor with two argument

template <class T>
VectorN<T> :: VectorN(const T ar2[] , int count)
{
    n = count;
    array = new T[n];
    for(int i=0; i < n; i++)
    {
       array[i] = ar2[i];
    }
}

//operator overloading for output operator <<

template <class S>
ostream& operator <<(ostream& ostr, const VectorN<S>& a)
{
    if(a.n ==0)
    {
        ostr << "["<<"]" ;
        return ostr;
    }
    else
    {
        ostr << "[" ;
      for(int i=0; i< a.n-1; i++)
       {
         ostr << a.array[i] << ", "; 
        }
        ostr << a.array[a.n-1] << "]";
      
      return ostr;
    }
}

// function to check size of vector i.e. No of element in dynamically allocated array

template <class T>
int VectorN<T> :: size() const
{
    return n;
}

//function to set instance back to vector of zero element.

template <class T>
void VectorN<T> :: clear() 
{
   array = nullptr;
   n = 0;
}

//Destructor for class VectorN

template <class T>
VectorN<T> :: ~VectorN()
{
    delete [] array;
    array =  nullptr;
    delete [] array;
}

//indexing operator overloading for reading value from instance

template <class T>
T VectorN<T> :: operator[](int index) const
{
    return array[index];
}

//indexing operator overloading for writing value to instance

template <class T>
T& VectorN<T> :: operator[](int index)
{
    return array[index];
}

// copy constructor

template <class T>
VectorN<T> :: VectorN(const VectorN& vec)
{
    n = vec.n;
    array = new T[n];
    for(int i =0 ; i<n; i++)
    {
        array[i] = vec.array[i];
    }
    
}

// Assignment(=) operator overloading

template <class T>
VectorN<T>& VectorN<T> :: operator = (const VectorN<T>& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    delete [] array;
    n = rhs.n;
    array = new T[rhs.n];
    for(int i=0; i<n; i++)
    {
        array[i] =  rhs.array[i];
    }
    return *this;
}

//operator overloading for addition (+) operator 
template <class T>
VectorN<T> VectorN<T> :: operator +(const VectorN<T>& rhs) const
{
    
    int size;
     T *ar;
    
    if(n < rhs.n)
      size = n;
    else
      size = rhs.n;
    
    ar = new T[size];
    
    for(int counter =0 ; counter < size ; counter++)
    {
        ar[counter] = array[counter] + rhs.array[counter];
    }
   const VectorN<T> v(ar,size);
   return v;
 
}

//operator overloading for comparision operator

template <class T>
bool VectorN<T> :: operator ==(const VectorN<T>& vec) const
{
    if(n != vec.n)
      {
        return false;
      }
    else
    {
        for(int index = 0; index < n; index++)
          {   
             if(array[index] != vec.array[index])
                { 
                    return false;
                    break;
                }
          }
        return true;
        
     }
    
}


#endif   /* VECTORN_H */      
