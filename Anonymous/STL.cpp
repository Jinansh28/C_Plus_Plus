#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool comparator(pair<int,int> p1,pair <int,int> p2){
    if(p1.second<p2.second) return true;
    else if(p1.second>p2.second) return false;
    else{
        if(p1.first<p2.first) return true;
        else return false;
    }
}
int main(){
    vector<int> a={1,2,3};
    vector<int> v(5,0);
    vector<int> vec2(v);
    cout<<vec2.size()<<endl;
    cout<<v.size()<<endl;
    cout<<a.size()<<endl;
    cout<<v.capacity()<<endl;
    a.push_back(5);
    for(int i:a){
        cout<<i<<" ";
    }
    a.pop_back();
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<a[2]<<endl;
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    cout<<a.at(1)<<endl;
    a.erase(a.begin(),a.begin()+1);
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    a.insert(a.begin(),1);
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>::iterator it;
    for(it=a.begin();it<a.end();it++){
        cout<<*(it);
    }
    cout<<endl;
    for(auto it=a.rbegin();it!=a.rend();it++){
        cout<<*(it);
    }
    cout<<endl;
    list<int> l={1,2,3,4};
    l.push_back(5);
    l.push_front(0);
    for(int i:l){
        cout<<i<<" ";
    }
    pair <int,int> p={1,2};
    cout<<endl<<p.first<<" "<<p.second<<endl;
    unordered_map<string,int> m;
    m["tv"]=100;
    m["laptop"]=100;
    m["headphone"]=140;
    for(auto p: m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m["laptop"]<<endl;
    vector<pair<int,int>> c={{1,2},{3,1},{7,1},{9,1}};
    sort(c.begin(),c.end(),comparator);
    for(auto p: c){
        cout<<p.first<< " "<<p.second<<endl;
    }
}