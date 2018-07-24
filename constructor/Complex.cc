#include "complex.h"
int main()
{
 Complex a(6.0);
 Complex b = a;
 cout << "print a";
 a.print();
 Complex c;
 c = add(a,b) ;
 cout<< "print non member add function result";
 c.print();
 c = c.add(a);
 cout<< "print member add function ";
 c.print(); 
 cout << a;
 return 0;

}
