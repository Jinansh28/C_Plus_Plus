#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Unoptimised
// int row(int i,int p,vector<vector<char>> &board){
//     for(int q=0;q<9;q++){
//         if(board[i][q]=='0'+p) return 0;
//     }
//     return 1;
// }

// int column(int j,int p,vector<vector<char>> &board){
//     for(int q=0;q<9;q++){
//         if(board[q][j]=='0'+p) return 0;
//     }
//     return 1;
// }

// int matrix(int i,int j,int p,vector<vector<char>> &board,unordered_set<char> &a,unordered_set<char> &b,unordered_set<char> &c,unordered_set<char> &d,unordered_set<char> &e,unordered_set<char> &f,unordered_set<char> &g,unordered_set<char> &h,unordered_set<char> &z){
//     char val = '0' + p;
//     if(i < 3 && j < 3 && a.count(val)) return 0;
//     else if(i < 3 && j >= 3 && j < 6 && b.count(val)) return 0;
//     else if(i < 3 && j >= 6 && c.count(val)) return 0;
//     else if(i >= 3 && i < 6 && j < 3 && d.count(val)) return 0;
//     else if(i >= 3 && i < 6 && j >= 3 && j < 6 && e.count(val)) return 0;
//     else if(i >= 3 && i < 6 && j >= 6 && f.count(val)) return 0;
//     else if(i >= 6 && j < 3 && g.count(val)) return 0;
//     else if(i >= 6 && j >= 3 && j < 6 && h.count(val)) return 0;
//     else if(i >= 6 && j >= 6 && z.count(val)) return 0;
//     return 1;
// }

// bool solver(int i,int j,vector<vector<char>>&board,unordered_set<char> &a,unordered_set<char> &b,unordered_set<char> &c,unordered_set<char> &d,unordered_set<char> &e,unordered_set<char> &f,unordered_set<char> &g,unordered_set<char> &h,unordered_set<char> &z){
//     if(j==9){
//         i++;
//         j=0;
//     }
//     if(i==9) return true;
//     if(board[i][j]!='.'){
//         j++;
//         return solver(i,j,board,a,b,c,d,e,f,g,h,z);
//     }
//     else{
//         for(int p=1;p<=9;p++){
//             if(row(i,p,board) && column(j,p,board) && matrix(i,j,p,board,a,b,c,d,e,f,g,h,z)){
//                 board[i][j]='0'+p;
//                 if(i<3 && j<3) a.emplace('0'+p);
//                 else if(i<3 && j<6) b.emplace('0'+p);
//                 else if(i<3 && j<9) c.emplace('0'+p);
//                 else if(i<6 && j<3) d.emplace('0'+p);
//                 else if(i<6 && j<6) e.emplace('0'+p);
//                 else if(i<6 && j<9) f.emplace('0'+p);
//                 else if(i<9 && j<3) g.emplace('0'+p);
//                 else if(i<9 && j<6) h.emplace('0'+p);
//                 else if(i<9 && j<9) z.emplace('0'+p);
//                 if(solver(i,j+1,board,a,b,c,d,e,f,g,h,z)) return true;
//                 board[i][j]='.';
//                 if(i<3 && j<3) a.erase('0'+p);
//                 else if(i<3 && j<6) b.erase('0'+p);
//                 else if(i<3 && j<9) c.erase('0'+p);
//                 else if(i<6 && j<3) d.erase('0'+p);
//                 else if(i<6 && j<6) e.erase('0'+p);
//                 else if(i<6 && j<9) f.erase('0'+p);
//                 else if(i<9 && j<3) g.erase('0'+p);
//                 else if(i<9 && j<6) h.erase('0'+p);
//                 else if(i<9 && j<9) z.erase('0'+p);
//             }
//         }
//         return false;
//     }
// }

// void solveSudoku(vector<vector<char>>& board) {
//     int i=0,j=0;
//     unordered_set<char> a,b,c,d,e,f,g,h,z;
//     for(int k=0;k<3;k++){
//         for(int l=0;l<3;l++){
//             a.emplace(board[k][l]);
//         }
//     }
//     for(int k=0;k<3;k++){
//         for(int l=3;l<6;l++){
//             b.emplace(board[k][l]);
//         }
//     }
//     for(int k=0;k<3;k++){
//         for(int l=6;l<9;l++){
//             c.emplace(board[k][l]);
//         }
//     }
//     for(int k=3;k<6;k++){
//         for(int l=0;l<3;l++){
//             d.emplace(board[k][l]);
//         }
//     }
//     for(int k=3;k<6;k++){
//         for(int l=3;l<6;l++){
//             e.emplace(board[k][l]);
//         }
//     }
//     for(int k=3;k<6;k++){
//         for(int l=6;l<9;l++){
//             f.emplace(board[k][l]);
//         }
//     }
//     for(int k=6;k<9;k++){
//         for(int l=0;l<3;l++){
//             g.emplace(board[k][l]);
//         }
//     }
//     for(int k=6;k<9;k++){
//         for(int l=3;l<6;l++){
//             h.emplace(board[k][l]);
//         }
//     }
//     for(int k=6;k<9;k++){
//         for(int l=6;l<9;l++){
//             z.emplace(board[k][l]);
//         }
//     }
//     solver(i,j,board,a,b,c,d,e,f,g,h,z);
// }


//Optimised

bool solver(int i,int j,vector<unordered_set<char>> &rows,vector<unordered_set<char>> &columns,vector<unordered_set<char>> &boxes,vector<vector<char>> & board){
    if(j==9){
        i++;
        j=0;
    }
    if(i==9) return true;
    char c=board[i][j];
    if(c!='.'){
        return solver(i,j+1,rows,columns,boxes,board);
    }
    else{
        for(char ch='1';ch<='9';ch++){
            int idx=(i/3)*3+(j/3);
            if(rows[i].find(ch)==rows[i].end() && columns[j].find(ch)==columns[j].end() && boxes[idx].find(ch)==boxes[idx].end()){
                board[i][j]=ch;
                rows[i].insert(ch);
                columns[j].insert(ch);
                boxes[idx].insert(ch);
                if(solver(i,j+1,rows,columns,boxes,board)){
                    return true;
                }
                board[i][j]='.';
                rows[i].erase(ch);
                columns[j].erase(ch);
                boxes[idx].erase(ch);
            }
        }
        return false;
    }
}


void solveSudoku(vector<vector<char>> & board){
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> columns(9);
    vector<unordered_set<char>> boxes(9);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                int ch=(i/3)*3+(j/3);
                boxes[ch].insert(board[i][j]);
            }
        }
    }
    solver(0,0,rows,columns,boxes,board);
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Sudoku before solving:\n";
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }

    solveSudoku(board);

    cout << "\nSudoku after solving:\n";
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }

    return 0;
}