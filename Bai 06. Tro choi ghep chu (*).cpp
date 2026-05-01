/*
Cho một ô chữ hình chữ nhật, mỗi ô chứa một ký tự. Người chơi cần tìm xem một từ nào đó có thể được tạo thành bằng cách nối các ký tự liên tiếp trong ô chữ hay không. Hai ký tự được gọi là liên tiếp nếu chúng nằm trong hai ô lân cận nhau theo hàng dọc, hàng ngang hoặc đường chéo.

INPUT

Dòng đầu tiên chứa từ cần tìm

Các dòng tiếp theo trong input có độ dài bằng nhau, mỗi dòng chứa một chuỗi gồm các chữ cái tiếng Anh , đây là các hàng trong ô chữ

Input kết thúc bằng một dòng chỉ chứa dấu .

OUTPUT

Nếu có thể tìm thấy từ đó trong ô chữ, xuất ra “true”, ngược lại xuất ra “false”

VÍ DỤ
Input
ABCCED

ABCE

SFCS

ADEE
Output
true

Input
ABCB

ABCE

SFCS

ADEE
Output
false
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int rows, cols;
vector<string> grid;
string targetWord;

int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool dfs(int r, int c, int wordIndex) {
    if (wordIndex == targetWord.length()) {
        return true;
    }

    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != targetWord[wordIndex]) {
        return false;
    }

    char temp = grid[r][c];
    grid[r][c] = '#'; 

    for (int i = 0; i < 8; i++) {
        int nextRow = r + dr[i];
        int nextCol = c + dc[i];
        
        if (dfs(nextRow, nextCol, wordIndex + 1)) {
            return true; 
        }
    }

    grid[r][c] = temp;
    return false;
}

int main() {
    if (!(cin >> targetWord)) return 0;

    string line;
    while (cin >> line && line != ".") {
        grid.push_back(line);
    }

    rows = grid.size();
    if (rows == 0) return 0;
    cols = grid[0].length();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == targetWord[0]) {
                if (dfs(i, j, 0)) {
                    cout << "true\n";
                    return 0; 
                }
            }
        }
    }

    cout << "false\n";
    return 0;
}
