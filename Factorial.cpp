#include <iostream>
using namespace std;
 int fac(int n){
 if (n==0 || n==1)
 return 1;
 else
  return n*fac(n-1);
 }
 int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    
    cout<<"fac="<<fac(n);
    return 0;
 }