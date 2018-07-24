#include "complex.h"


void Complex ::print() const
{
 cout << "(" << r << "," << i << ")" << endl;
}

Complex :: Complex(const Complex& c)
{
 r = c.r;
 i = c.i;
}

Complex Complex :: add(const Complex& c) const
{
  Complex result;
  result.re(r + c.r);
  result.im(i + c.i);
  return result;
}

Complex add(const Complex& a, const Complex& b)
{
 Complex result(a.re() + b.re(), a.im() + b.im());
  return result;
} 

Complex Complex::operator + (const Complex & b)
{
 Complex Temp;
 Temp.re(r + b.r);
 Temp.im(i + b.i);
 return Temp;
}

Complex operator+ (const Complex& a, const Complex& b)
{
 Complex result(a.re() + b.re() , a.im() + b.im());
 return result;
}


ostream& operator << (ostream& ostr, const Complex& c)
{
 ostr<< "(" << c.re() <<"," <<c.im() << ")";
return ostr;
} 
