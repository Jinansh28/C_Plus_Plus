#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    stack<int> s;
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        s.push(i);
    }
    while (s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();
        if (mat[i][j] == 0) 
            s.push(i);
        else 
            s.push(j);
    }
    int cand = s.top();
    for (int i = 0; i < n; i++) {
        if (i == cand) continue;
        if (mat[i][cand] == 0 || mat[cand][i] == 1) {
            return -1;
        }
    }
    return cand;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    cout<<celebrity(mat);
    return 0;
}
