#include<iostream>
#include<climits>
using namespace std;

int main(){
    int a[]={10,7,6,9,400,2000};
    int size=sizeof(a)/sizeof(a[0]);
    int b=size*size;
    int min=INT_MAX;
    int profit=0;

    for(int k=1;k<=b;k++){

        int i=(k-1)/size;
        int j=k%size-1;
        if(j==-1){
            j=size-1;
        }
        
        if(j>=i){
            int c=a[i]-a[j];
            if(c<min){
                min=c;
                profit=c*-1;
            }
        }
    }
    cout<<profit;
}
