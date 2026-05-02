/*
Sudoku là một trò chơi phổ biến rộng rãi dùng để giết thời gian và rèn luyện trí tuệ. 
Trong bài này, ta sẽ xét đến trường hợp Sudoku 9 × 9
Một Sudoku kích thước 9 × 9 được chia làm 9 hình vuông cơ sở, thu được bằng cách cắt đường cắt mỗi chiều thành ba phần bằng nhau. 
Một Sudoku được xem là hợp lệ nếu mỗi khi ta xét một hàng, một cột, hoặc một hình vuông cơ sở, ta sẽ thu được một hoán vị của 9 số tự nhiên đầu tiên. 
Cho một Sudoku trong đó một vài ô còn trống chưa được điền. Hãy điền các số vào các ô trống đó sao cho tạo được một Sudoku hợp lệ.
Input
Gồm một ma trận có kích thước 9×9, trong đó các ô được điền sẵn sẽ mang số tương ứng, các ô chưa được điền sẽ mang ký tự X. 
Input đảm bảo không có quá 5 ô trống chưa được điền.

Output
Gồm một ma trận có kích thước 9 × 9, thể hiện một Sudoku hợp lệ với dữ liệu mà đề bài cho.
Nếu có nhiều trường hợp thỏa mãn, hãy xuất ra một trường hợp bất kỳ
*/
#include <iostream>
#include <vector>
using namespace std;

char board[9][9];

bool isValid(int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false;

        if (board[i][col] == num) return false;

        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        if (board[startRow + i / 3][startCol + i % 3] == num) return false;
    }
    return true;
}

bool solve() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == 'X') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isValid(r, c, num)) {
            
                        board[r][c] = num;
                      
                        if (solve()) return true;
                
                        board[r][c] = 'X';
                    }
                }
      
                return false;
            }
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    
    if (solve()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
