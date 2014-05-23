#include "Sudoku.h"

namespace MathProblems {

Sudoku::~Sudoku()
{
}

bool Sudoku::isValidSudoku()
{
    const int vecSize = 9;
    bool hasNum[vecSize];
    for (int i = 0; i < vecSize; ++i)
    {
        for (int ix = 0; ix < vecSize; ++ix)
            hasNum[ix] = 0;
        for (int j = 0; j < vecSize; ++j)
        {
            char c = board[i][j];
            if (c >= '1' && c <= '9')
            {
                int num = c - '1';
                if (hasNum[num])
                    return false;
                hasNum[num] = 1;
            }
        }
    }

    for (int j = 0; j < vecSize; ++j) {
        for (int ix = 0; ix < vecSize; ++ix)
            hasNum[ix] = 0;
        for (int i = 0; i < vecSize; ++i) {
            char c = board[i][j];
            if (c >= '1' && c <= '9')
            {
                int num = c - '1';
                if (hasNum[num])
                    return false;
                hasNum[num] = 1;
            }
        }
    }

    for (int i = 0; i < vecSize; i += 3) {
        for (int j = 0; j < vecSize; j += 3) {
            for (int ix = 0; ix < vecSize; ++ix)
                hasNum[ix] = 0;
            for (int ii = i; ii < i + 3; ii++) {
                for (int jj = j; jj < j + 3; jj++) {
                    char c = board[ii][jj];
                    if (c >= '1' && c <= '9')
                    {
                        int num = c - '1';
                        if (hasNum[num])
                            return false;
                        hasNum[num] = 1;
                    }
                }
            }
        }
    }
    return true;
}

}
