#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

namespace MathProblems {

using std::vector;
class Sudoku
{

    public:
        Sudoku(vector<vector<char> > board1):
            board(board1) {}
        virtual ~Sudoku();
        bool isValidSudoku();

    private:
        vector<vector<char> > board;
};
}

#endif // VALIDSUDO_H
