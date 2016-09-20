#include<iostream>
#include<cstring>
 using namespace std;
class L
{
 private:
  char *arr;
  int len;
 public:
  L();
  L(const char *);
  L(const L &);
  ~L();
  L &operator=(const char *);
  L &operator=(const L &);
  L operator+(const L &);
  friend istream &operator>>(istream &,L &);
  friend ostream &operator<<(ostream &,L &);

};

L::L()
{
 arr=new char[1];
 arr[0]='\0';
 len=0;
}
L::L(const char *p)
{
 len=strlen(p);
 arr=new char[len+1];
 strcpy(arr,p);
}
L::L(const L &p)
{
 len=p.len;
 arr=new char[len+1];
 strcpy(arr,p.arr);
}
L::~L()
{
 delete [] arr;
 cout<<"-------"<<endl;
}
istream &operator>>(istream &in,L &s)
{
 in>>s.arr;
 return in;
}
ostream &operator<<(ostream &out,L &s)
{
 out<<s.arr;
 return out;
}
L &L::operator=(const char *p)
{
 delete [] arr;
 len=strlen(p);
 arr=new char[len+1];
 strcpy(arr,p);
 return *this;
}
L &L::operator=(const L &p)
{
 delete [] arr;
 len=p.len;
 arr=new char[len+1];
 strcpy(arr,p.arr);
 return *this;
}
L L::operator+(const L &p)
{
 L s;
 s.len=len+p.len;
 delete [] s.arr;
 s.arr=new char[s.len+1];
 strcpy(s.arr,arr);
 strcat(s.arr,p.arr);
 return s;
}

 class Employee
{
 L name;
protected:
 float sal;
public:
 Employee(const char *p,float m)
{
 name=p;
 sal=m;
}
 void pay()
{
 cout<<"你的薪水是："<<sal<<endl;
} 
};
 class Officer:public Employee
{
 int y;
 public:
  Officer(const char *name,float sal,int p):Employee(name,sal)
 {
  y=p;
 }
void counts()
 {
  sal=y*100+sal;
 }
};
int main()
{
 Officer e("张三",2000,5);
 e.counts();
 e.pay();

 return 0;
}
