#include<iostream>
#include<cstring>
#include "0811yuepanfeng.h"
using namespace std;
Mystring::Mystring()
{
 arr=new char[1];
 arr[0]='\0';
 len=0;
}
Mystring::Mystring(const char *s)
{
  len=strlen(s);
  arr=new char[len+1];
  strcpy(arr,s);
}
Mystring::Mystring(const Mystring &s)
{
  len=s.len;
  arr=new char[len+1];
  strcpy(arr,s.arr);
}
Mystring::~Mystring()
{
cout<<"--------"<<endl;
}
istream &operator>>(istream &in,Mystring &s)
{
 in>>s.arr;
 return in;
}
ostream &operator<<(ostream &out,Mystring &s)
{
 out<<s.arr;
 return out;
}
int Mystring::operator==(const Mystring &s)
{
 if(len==s.len&&strcmp(arr,s.arr)==0)
  {
   return 0;
  }
  return 1;
}
int Mystring::operator>(const Mystring &s)
{
 if(strcmp(arr,s.arr)>0)
  {
   return 0;
  }
  return 1;
}
int Mystring::operator<(const Mystring &s)
{
 if(strcmp(arr,s.arr)<0)
  {
   return 0;
  }
  return 1;
}
int Mystring::operator>=(const Mystring &s)
{
 if(strcmp(arr,s.arr)>=0)
  {
   return 0;
  }
  return 1;
}
int Mystring::operator<=(const Mystring &s)
{
 if(strcmp(arr,s.arr)<=0)
  {
   return 0;
  }
  return 1;
}
Mystring &Mystring::operator=(const Mystring &s)
{
  delete [] arr;
  len=s.len;
  arr=new char [len+1];
  strcpy(arr,s.arr);
  return *this;
}
Mystring &Mystring::operator=(const char *s)
{
  delete [] arr;
  len=strlen(s);
  arr=new char [len+1];
  strcpy(arr,s);
  return *this;
}
int Mystring::operator!=(const Mystring &s)
{
 if(strcmp(arr,s.arr)!=0)
  {
   return 0;
  }
  return 1;
}
Mystring Mystring::operator+(const Mystring &s)
{
  Mystring snew;
  snew.len=len+s.len;
  delete [] snew.arr;
  snew.arr=new char[snew.len+1];
  strcpy(snew.arr,arr);
  strcat(snew.arr,s.arr);
  return snew;
}

