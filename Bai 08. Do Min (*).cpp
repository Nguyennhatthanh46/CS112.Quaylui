/*
Trò chơi Minesweeper là một tựa game nổi tiếng ra mắt lần đầu vào năm 1989. Trò chơi diễn ra trên một bảng chữ nhật kích thước N x M ô, trong đó một số ô chứa mìn và các ô còn lại là an toàn. Nhiệm vụ của người chơi là tìm và đánh dấu tất cả các ô có mìn. Nếu người chơi chọn trúng ô có mìn thì sẽ bị xử thua; ngược lại, nếu tìm ra chính xác toàn bộ vị trí mìn thì sẽ giành chiến thắng.

Cũng là một ngày cuối tuần, nhưng câu đố "Hidden words" đã được Meow chơi phá đảo. Vì quá chán, cô nàng lôi Minesweeper ra chơi. Sau khi cày cuốc qua 7749 lần, cô đã trở thành bậc thầy của trò chơi này, tự tin có thể chiến thắng bất chấp mọi kiểu chơi. Cảm thấy rất tự hào về thành tựu của mình, cô nàng sẵn tiện nghĩ ra một câu đố để thử thách mọi người. Nội dung câu đố có thể tóm tắt như sau:

Cho một ma trận A kích thước N x M. Giá trị A[x][y] = k mang ý nghĩa là có k quả mìn nằm kề với ô (x, y).
(Lưu ý: Hai ô (x1, y1) và (x2, y2) được gọi là kề nhau khi |x1 - x2| + |y1 - y2| = 1)

Yêu cầu:
Hãy xây dựng mảng B kích thước N x M từ mảng A đã cho, sao cho:
- B[x][y] = 1 nếu có mìn tại ô (x, y).
- B[x][y] = 0 nếu không có mìn tại ô (x, y).

(Xem ví dụ để hiểu rõ hơn)
Input:
- Dòng đầu gồm 2 số nguyên dương N, M là kích thước của bảng.
- N dòng tiếp theo, mỗi dòng gồm M số nguyên, mỗi số nguyên có giá trị từ 0 đến 4 thể hiện số quả mìn nằm kề với ô (x, y) tương ứng.

Output:
- Ghi ra gồm N dòng, mỗi dòng gồm M ký tự thể hiện ô có mìn là '1' và ô không có mìn là '0'. Nếu có nhiều đáp án thỏa mãn, có thể ghi bất kỳ một đáp án.
- Dữ liệu đảm bảo luôn tồn tại đáp án.

Constraints:
- 1 <= N, M <= 40

Example:
Input
4 4

2 0 1 1
0 2 1 0
1 1 1 2
1 1 2 1

Output 
0 1 0 0
1 0 0 1
0 0 0 0
0 1 1 1
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> A, B;

bool deduce(int r, int &conflict_index) {
    if (r == N) {
        for (int j = 1; j <= M; ++j) {
            if (B[N - 1][j] + B[N][j - 1] + B[N][j + 1] != A[N][j]) {
                return false;
            }
        }
        return true;
    }

    for (int c = 1; c <= M; ++c) {
        int current_sum = B[r - 1][c] + B[r][c - 1] + B[r][c + 1];
        int val = A[r][c] - current_sum;

        if (val == 0 || val == 1) {
            B[r + 1][c] = val;
        } else {
            conflict_index = c + r - 1; 
            return false;
        }
    }
    
    return deduce(r + 1, conflict_index);
}

bool backtrackRow1(int c, int &conflict_index) {
    if (c > M) {
        return deduce(1, conflict_index);
    }

    for (int val : {0, 1}) {
        B[1][c] = val;

        if (c > 1) {
            int partial_sum = B[1][c - 2] + B[1][c];
            if (partial_sum > A[1][c - 1]) continue;
            if (N == 1 && partial_sum != A[1][c - 1]) continue;
        }

        if (backtrackRow1(c + 1, conflict_index)) return true;

        if (c > conflict_index + 1) return false;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M)) return 0;

    A.assign(N + 2, vector<int>(M + 2, 0));
    B.assign(N + 2, vector<int>(M + 2, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> A[i][j];
        }
    }

    int conflict_index = M;
    if (backtrackRow1(1, conflict_index)) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cout << B[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
