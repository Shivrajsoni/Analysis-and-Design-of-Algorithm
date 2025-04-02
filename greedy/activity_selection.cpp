#include<iostream>
using namespace std;


bool compare( vector<int>&a , vector<int> &b){
  return a[1]<b[1];
}

void activity_selection(  vector<vector<int> > &activitites, int size){

  // sort on last index
  // put last Index variable and compare it with next element first term

  sort(activitites.begin(),activitites.end(),compare);
  
  for(int i =0 ;i<size ;i++){
    cout<<""<<activitites[i]<<"";
  }

  int last_index = 0;
  for(int i =0;i<size;i++){
    if(last_index< activitites[i][0]){
      cout<<activitites[i][0]<<"->"<<activitites[i][1]<<endl;

      last_index = activitites[i][1];
    }
  }

}



int main(){


  int size = 8;
 vector<vector<int> > activitites  = {{1,3},{2,5},{3,4},{6,8},{5,7},{9,19},{7,10},{12,14}};
  activity_selection(activitites,size);

  return 0;
}
