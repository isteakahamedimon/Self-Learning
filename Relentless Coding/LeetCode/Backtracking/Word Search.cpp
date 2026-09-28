#include<iostream>

class Solution {
public:
    bool ans = false;
    int rows, columns;
    std::vector<bool> found;
    int a = 0;
    std::string newStr;
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        rows = board.size();
        columns = board[0].size();

        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<columns; j++) {
                search(board, word, visited, i, j);
            }
        }

        return ans;
    }

private:
    void search(std::vector<std::vector<char>>& board, 
            std::string word, 
            std::vector<std::vector<bool>>& visited, 
            int row, int column) 
    {
        if(word == newStr) {
            ans = true;
            return;
        }
        if(row<0 || column<0 || row>rows-1 || column>columns-1) {
            return;
        }
        if(visited[row][column]) {
            return;
        }

        if(board[row][column] != word[a]) {
            return;
        }


        newStr.push_back(board[row][column]);
        visited[row][column] = true;
        a++;

        search(board, word, visited, row, column+1);
        search(board, word, visited, row-1, column);
        search(board, word, visited, row, column-1);
        search(board, word, visited, row+1, column);

        newStr.pop_back();
        visited[row][column] = false;
        a--;
    }
};


int main()
{
    Solution s;
    bool ans;
    std::string word = "ABPPALEETACD";
    std::vector<std::vector<char>> board;
    board = {
        {'A', 'B', 'C', 'D'},
        {'P', 'P', 'A', 'T'},
        {'A', 'L', 'E', 'E'}
    };
    
    ans = s.exist(board, word);
    std::cout << "ans: " << ans << std::endl;

    return 0;
}
