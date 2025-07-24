#include<iostream>
#include<vector>
using namespace std;

//Wrong
// vector<int> spiralOrder(vector<vector<int>>& matrix){
//     vector<int> ans;
//     int m=matrix.size(),n=matrix[0].size();
//     int top=0,bottom=m-1,left=0,right=n-1;
//     int i=0,j=0;
//     while(top<=bottom && right<=left){
//         if(i==top && j<right){
//             ans.emplace_back(matrix[i][j++]);
//             if(j==right) top++;
//         }
//         else if(i<bottom && j==right){
//             ans.emplace_back(matrix[i++][j]);
//             if(i==bottom) right--;
//         }
//         else if(i==bottom && j>left){
//             ans.emplace_back(matrix[i][j--]);
//             if(j==left) bottom--;
//         }
//         else if(j==left && i>top){
//             ans.emplace_back(matrix[i--][j]);
//             if(i==top) left++;
//         }
//     }
//     return ans;
// }

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m=matrix.size(),n=matrix[0].size();
    int top=0,left=0,right=n-1,bottom=m-1;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++){
            ans.emplace_back(matrix[top][j]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.emplace_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int j=right;j>=left;j--){
                ans.emplace_back(matrix[bottom][j]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.emplace_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;  
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=spiralOrder(matrix);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}