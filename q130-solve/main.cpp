#include <string.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        if (board.empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();
        unsigned char *o = new unsigned char[m * n];
        memset(o, 0, m * n);

        map<unsigned int, bool> mapFill;
        unsigned int x = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' || o[i * n + j] != 0) {
                    continue;
                }

                // 深度遍历所有O字符
                bool bFill = true;
                x++;
                dfs(board, o, m, n, x, i, j, bFill);
                mapFill[x] = bFill;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                unsigned int t = o[i * n + j];
                if (t != 0 && mapFill[t]) {
                    board[i][j] = 'X';
                }
            }
        }

        delete[] o;
    }

    void dfs(vector<vector<char> >& board, unsigned char *o, 
        int m, int n, unsigned int x, 
        int i, int j, bool &bFill) {
        if (i == m || j == n || i < 0 || j < 0) {
            bFill = false;
            return;
        } else if (board[i][j] == 'X' || o[i * n + j] != 0) {
            return;
        }

        o[i * n + j] = x;
        dfs(board, o, m, n, x, i, j + 1, bFill);
        dfs(board, o, m, n, x, i + 1, j, bFill);
        dfs(board, o, m, n, x, i, j - 1, bFill);
        dfs(board, o, m, n, x, i - 1, j, bFill);
    }
};

template<typename T>
void dump(vector<T> &v)
{
    for (unsigned int i = 0; i < v.size(); i++) {
        cout << i << ": " << v[i] << endl;
    }
}

int main(int argc, char *argv[])
{
    Solution s;
    vector<vector<char> > board;
    board.push_back({'X', 'X', 'X', 'X'});
    board.push_back({'X', 'O', 'O', 'X'});
    board.push_back({'X', 'X', 'O', 'X'});
    board.push_back({'X', 'O', 'X', 'X'});

    s.solve(board);

    for (unsigned int i = 0; i < board.size(); i++) {
        dump(board[i]);
    }

    return 0;
}