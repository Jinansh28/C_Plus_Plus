#include<iostream>
using namespace std;

int main(){

    int a[]={4,2,7,8,1,2,5,4};
    int b[]={1,2,3,4,2,5,3,4,4};

    int sizea=sizeof(a)/sizeof(a[0]);
    int sizeb=sizeof(b)/sizeof(b[0]);
    int c[sizea],d[sizeb],k=0,l=0;

    for(int i=0;i<sizea;i++){
        c[i]=0;
    }

    for(int i=0;i<sizeb;i++){
        d[i]=1;
    }

    for(int i=0;i<sizea;i++){
        bool flag=true;
        for(int j=0;j<i;j++){
            if(a[j]==a[i]){
                flag=false;
            }
        }
        if(flag==true){
            c[k]=a[i];
            k++;
        }
    }

    for(int i=0;i<sizeb;i++){
        bool flag=true;
        for(int j=0;j<i;j++){
            if(b[j]==b[i]){
                flag=false;
            }
        }
        if(flag==true){
            d[l]=b[i];
            l++;
        }
    }

    sizea=sizeof(c)/sizeof(c[0]);
    sizeb=sizeof(d)/sizeof(d[0]);

    cout<<sizea<<endl<<sizeb<<endl;

    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizeb;j++){
            if(c[i]==d[j]){
                cout<<c[i]<<" ";
                break;
            }
        }
    }
    
    return 0;
}