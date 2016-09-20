#include<iostream>
using namespace std;
class stack
{
 int SIZE;
 int *arr;
 int i;
 public:
 stack(int);
 ~stack();
 stack(const stack &);
 stack &operator=(stack &);
 stack &operator<<(int);
 friend ostream &operator<<(ostream &out,stack &y);
};
stack::stack(int n)
{
  this->SIZE=n;
  this->i=0;
  this->arr=new int[n];
}
stack::~stack()
{
 cout<<"_____________"<<endl;
}
 stack::stack(const stack &y)
{
 int j;
 this->SIZE=y.SIZE;
 this->i=y.i;
 this->arr=new int[y.SIZE];
 for(j=0;j<this->SIZE;j++)
 {
  this->arr[j]=y.arr[j];
 }
}
  stack &stack::operator=(stack &y)
{
 int j;
 this->SIZE=y.SIZE;
 this->i=y.i;
 delete [] this->arr;
 this->arr=new int[this->SIZE];
 for(j=0;j<this->SIZE;j++)
 {
  this->arr[j]=y.arr[j];
 }
 return *this;
}

stack &stack::operator<<(int n)
{
 if(i==SIZE)
 {
  return *this;
 }
 arr[i]=n;
 i++;
}
ostream &operator<<(ostream &out,stack &y)
{
 if(y.i==0)
 {
  return out;
 }
 y.i--;
 out<<y.arr[y.i];
}
int main()
{
 stack y1(6);
 y1<<1<<2<<3<<4<<5;
 stack y2=y1;
 cout<<y2<<y2<<y2<<y2<<y2<<"\n";
 return 0;
}
