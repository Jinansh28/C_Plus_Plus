#include<iostream>
using namespace std;

pair<int,int> linearSearch(int arr[][4],int r,int c,int key){
    pair<int,int> p={-1,-1};
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==key){
                p={i,j};
                return p;
            }
        }
    }
    return p;
}

int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int key=10;
    pair <int,int> p=linearSearch(arr,3,4,key);
    cout<<p.first<<" "<<p.second;
}