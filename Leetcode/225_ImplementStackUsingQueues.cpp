#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    MyStack() {}

    deque<int> q;

    void push(int x) {
        q.push_back(x);
    }

    int pop() {
        int a = q.back();
        q.pop_back();
        return a;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack s;

    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;

    s.push(3);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;

    return 0;
}
