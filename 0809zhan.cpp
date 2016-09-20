#include<iostream>
using namespace std;
#define size 10
class stack
{
int p[size];
int i;
public:
stack();
void push(int );
int pop();
~stack();
stack &operator<<(int);
friend ostream &operator<<(ostream &out,stack &yue);

};
stack::stack()
{
 i=0;
}
 stack::~stack()
{
 cout<<"----------\n";
}
void stack:: push(int a)
{
 if(i==size)
 {
  cout<<"无空位！\n";
  return ;
 }
 p[i]=a;
 i++;
}
int stack::pop()
{
 if(i==0)
 {
  cout<<"已空！\n";
  return i;
 }
 i--;
 return p[i];
}
stack &stack::operator<<(int n)
{
 if(i==size)
 {
  return *this;
 }
 p[i]=n;
 i++;
}
ostream &operator<<(ostream &out,stack &yue)
{
 if(yue.i==0)
 {
  return out;
 }
 yue.i--;
 out<<yue.p[yue.i];
}
int main()
{ 
  
  stack yue;
  yue<<1<<2<<3<<4<<5;
  cout<<yue<<yue<<yue<<endl;
return 0;
}
