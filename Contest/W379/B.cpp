/********************************************
 * author : Jie Chen (3rd Year CS)
 * school : Rochester Institute of Technology
 * created: 01.06.2024 21:32:38
*********************************************/

using i64 = long long;
using Position = pair<int, int>;

#define row first
#define col second

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        Position rook(a, b);
        Position bishop(c, d);
        Position queen(e, f);

        if (rook.row == queen.row) {
            if (rook.row == bishop.row && min(rook.col, queen.col) < bishop.col && bishop.col < max(rook.col, queen.col)) {
                return 2;
            }
            return 1;
        }
        if (rook.col == queen.col) {
            if (rook.col == bishop.col && min(rook.row, queen.row) < bishop.row && bishop.row < max(rook.row, queen.row)) {
                return 2;
            }
            return 1;
        }

        int qdia = queen.row - queen.col;
        int bdia = bishop.row - bishop.col;
        int rdia = rook.row - rook.col;

        if (qdia == bdia) {
            if (qdia == rdia && min(bishop.row, queen.row) < rook.row && rook.row < max(bishop.row, queen.row)) {
                return 2;
            }
            return 1;
        }

        qdia = -queen.row - queen.col;
        bdia = -bishop.row - bishop.col;
        rdia = -rook.row - rook.col;

        if (qdia == bdia) {
            if (qdia == rdia && min(bishop.row, queen.row) < rook.row && rook.row < max(bishop.row, queen.row)) {
                return 2;
            }
            return 1;
        }

        return 2;
    }
};

// ~ JustJie