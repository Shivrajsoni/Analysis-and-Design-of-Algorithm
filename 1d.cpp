#include<iostream>
using namespace std;

void 1dPeak(int arr[], int start,int end,int n){
  int mid = start+(end-start)/2;
  if(mid< n-1 && arr[mid]<arr[mid+1]){
    return 1dPeak(arr,mid+1,end,n);
  }
  else if(mid>0 && arr[mid]<arr[mid-1]){
    return 1dPeak(arr,start,mid-1,n);
  }
  else{
    return mid;
  }
}

int main(){
  int n;
  cin >>n;
  int arr[n];
  for(int i =0;i<n;i++){
    cin>>arr[i];
  }
  cout<< "Peak : "<< arr[1dPeak(arr,0,n-1,n)];
  return 0;
}
