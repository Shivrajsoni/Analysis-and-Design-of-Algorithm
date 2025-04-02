#include<iostream>
using namespace std;

int main(){
  int na;
  cout<<"Enter the size of array 1";
  cin>>na;
  int a[na];
  cout<<"Enter the value's of array 1 :";
  for(int i =0;i<na;i++){
    cout<<i<<"th value : ";
    cin>> a[i];
    cout<<endl;
  }

  int nb;
  cout<<"Enter the size of array 2";
  cin>>nb;
  int b[nb];
  cout<<"Enter the value's of array 2 :";
  for(int j =0;j<nb;j++){
    cout<<j<<"th value : ";
    cin>> b[j];
    cout<<endl;
  }

  cout<<"sorted Array is "<<endl;
  int c[na+nb];
  int i =0,j=0,p=0;
  while(i<na && j<nb){
    if(a[i]<b[j]){
      c[p] = a[i];
      p++;
      i++;
    }
    else{
      c[p] = b[j];
      p++;
      j++;
    }
  }
  while(j<nb){ 
    c[p] = b[j];
    p++;
    j++;
  }

  while(i<na){
    c[p] = a[i];
    p++;
    i++;
  }

  for(int i =0;i<na+nb;i++){
    cout<<c[i]<<" ";
  }
  return 0;
}

