#include<iostream>
using namespace std;
int main(){
    int s,c,r;
    cout<<"Enter number of rows";
    cin>>r;
    cout<<"Enter number of columns";
    cin>>c;
    cout<<"Enter size of diamond";
    cin>>s;
    int a=s*2;
    int p=a*a*c*r;
    for(int o=1;o<=p;o++){
        int j=o%a;
        int i=(o/(a*c))%a;
        i+=1;
        if(o%(a*c)==0){
            i--;
        }
        if(j==0){
            j=a;
        }
        int b=i-j;
            int d=j-i;
            int e=i+j;
            if((e<=s)||(e>=(3*s)+2)||(b>=s+1)||(d>=s+1)){
                cout<<"e";
            }
            else if(((e==(2*a)-s+1 && (i>s && j>s)) || (e==s+1)&&((i<=s && j<=s)))){
                cout<<"/";
            }
            else if((b==s|| d==s) &&((i>s && j<=s)||(i<=s && j>s))){
                cout<<"\\";
            }
            else{
                cout<<"o";
            }
            if(o%(a*c)==0){
            cout<<endl;
        }
    }
    return 0;
}