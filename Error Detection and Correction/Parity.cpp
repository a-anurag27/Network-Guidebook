#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class par
{
int i[8],o[8];
public:
void getpi()
{
char c;
cout<<"\nEnter the input message : \n";
for(int j=0;j<7;j++)
cin>>i[j];
cout<<"\nEnter Even or Odd[e/o] : ";
cin>>c;
if(c=='e')
{
i[7]=evenp();
cout<<"\nAfter Parity generation : ";
for(int g=0;g<8;g++)
cout<<i[g];
}
else{
i[7]=oddp();
cout<<"\nAfter Parity generation : ";
for(int g=0;g<8;g++)
cout<<i[g];}
}
void getpo()
{
cout<<"\nEnter the recieved message : \n";
for(int j=0;j<8;j++)
cin>>o[j];
char c;
int m=0;
cout<<"Check for even/odd parity [e/o]:";
cin>>c;
if(c=='e')
{
for(int l=0;l<8;l++)
if(o[l]==1)
m+=1;
if(m%2==0)
cout<<"No error!";
else
cout<<"Error in transmission!";
}
else
{
for(int l=0;l<8;l++)
if(o[l]==1)
m+=1;
if(m%2!=0)
cout<<"No error!";
else
cout<<"Error in transmission!";
}
}
int evenp()
{
int j=0,k=0;
for(j=0;j<7;j++)
if(i[j]==1)
k+=1;
if(k%2==0)
return 0;
else
return 1;
}
int oddp()
{
int j=0,k=0;
for(j=0;j<7;j++)
if(i[j]==1)
k+=1;
if(k%2==0)
return 1;
else
return 0;
}
};
int main()
{
par A;
A.getpi();
A.getpo();
return 0;
}
