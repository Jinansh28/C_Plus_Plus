#include <bits/stdc++.h>
using namespace std;

// class MinStack {
// public: 
//     stack<pair<int,int>> s;
    
//     MinStack() {}

//     void push(int val) {
//         if(s.empty()){
//             s.push({val, val});
//         }
//         else {
//             int va = min(s.top().second, val);
//             s.push({val, va});
//         }
//     }

//     void pop() {
//         s.pop();
//     }

//     int top() {
//         return s.top().first;
//     }

//     int getMin() {
//         return s.top().second;
//     }
// };





//Space O(n)
class MinStack {
public: 
    stack<long long int> s;
    long long int minValue;
    MinStack() {}

    void push(int val) {
        if(s.empty()){
            s.push(val);
            minValue = val;
            return;
        }
        if(val < minValue){
            s.push(((long long)2*val)-minValue);
            minValue = val;
        }
        else{
            s.push(val);
        }
    }

    void pop() {
        if(s.top() >= minValue){
            s.pop();
        }
        else{
            minValue = (2*minValue)-s.top();
            s.pop();
        }
    }

    int top() {
        if(s.top() < minValue) return minValue;
        return s.top();
    }

    int getMin() {
        return minValue;
    }
};



int main() {
    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Current Min: " << st.getMin() << endl; // -3

    st.pop();

    cout << "Top element: " << st.top() << endl;   // 0
    cout << "Current Min: " << st.getMin() << endl; // -2

    return 0;
}
