#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int k) {
        if(k == word.length()) {
            return true;
        }
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[k]) {
            return false;
        }
        
        char temp = board[r][c];
        board[r][c] = '#'; // mark as visited

        bool res = dfs(board, word, r + 1, c, k + 1) ||
                   dfs(board, word, r - 1, c, k + 1) ||
                   dfs(board, word, r, c + 1, k + 1) ||
                   dfs(board, word, r, c - 1, k + 1);

        board[r][c] = temp; // unmark
        
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    
    if(solution.exist(board, word)) {
        cout << "Word found in the board." << endl;
    } else {
        cout << "Word not found in the board." << endl;
    }

    return 0;
}
