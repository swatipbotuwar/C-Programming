#include<iostream>
#include<cstdlib>
using std:: cout;
using std :: endl;
using std ::ostream;

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
 double r;
 double i;
 public :
 Complex(double real=0.0, double im=0.0):r(real), i(im) {}  //default constructor
 void print() const;
 Complex(const Complex& c); //copy constructor 
 void re(double d) 
{
   r= d;
}  
 double re() const { return r;}
 void im(double d1) 
{
 i =d1;
}
 double im() const  {return i;}

 Complex add(const Complex& c) const; //member add function
 Complex operator + (const Complex & b); //member operator overload
 Complex operator - (const Complex & b);
 Complex operator -(void) const
 {
   return Complex(-r, -i);
 }
//friend ostream& operator<<(ostream& ostr, const Complex& c);

};

 Complex add(const Complex& a, const Complex &b);
 Complex operator +(const Complex & a, const Complex & b);
 ostream& operator<<(ostream& ostr, const Complex& c);
#endif /* End of header */

