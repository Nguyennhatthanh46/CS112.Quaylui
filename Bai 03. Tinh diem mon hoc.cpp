/*
Môn học X có n cột điểm. Hệ số của mỗi cột điểm đã được phòng đào tạo quy định trước. 
Tuy nhiên do không muốn làm đủ n bài tập để lấy điểm, sinh viên lớp X đã thỏa thuận với giảng viên chỉ làm một đồ án duy nhất lấy điểm cho cả môn. Sau khi chấm điểm đồ án xong bây giờ giảng viên phải nhập đủ n cột điểm cho phòng đào tạo nhưng vẫn phải đảm bảo khi chia trung bình môn học n cột điểm này sẽ vẫn bằng với i điểm, là điểm đồ án của sinh viên.

Hãy phát sinh tất cả cách ghi điểm giảng viên có thể ghi cho sinh viên đó.

Điểm mỗi cột không được phép là điểm liệt (tức 0 điểm) và sẽ được làm tròn đến 0.25, điểm trung bình môn được làm tròn đến 0.1


INPUT

Dòng đầu tiên chứa số nguyên dương n, n<10.

n dòng tiếp theo mỗi dòng chứa một số nguyên dương đây lần lượt là các hệ số của cột điểm. Hệ số của một cột là tỷ lệ % của cột đó trong điểm trong bình môn học

Dòng cuối cùng của input chứa số i, là điểm số trung bình môn của sinh viên.

 
OUTPUT

Ứng với mỗi cách ghi điểm cuả giảng viên xuất ra trên một hàng các điểm số của mỗi cột điểm, cách nhau bởi khoảng trắng.

VÍ DỤ
INPUT
3

20

30

50

9.5


OUTPUT
7.25 10 10
7.5 10 10
7.75 9.75 10
8 9.5 10
8 9.75 10
8 10 9.75
8.25 9.5 10
8.25 9.75 9.75
8.25 10 9.75
8.5 9.25 10
8.5 9.75 9.75
8.5 10 9.5
8.75 9 10
8.75 9.25 10
8.75 9.5 9.75
8.75 10 9.5
9 9 10
9 9.25 9.75
9 9.5 9.75
9 9.75 9.5
9.25 8.75 10
9.25 9.25 9.75
9.25 9.5 9.5
9.25 9.75 9.5
9.25 10 9.25
9.5 8.5 10
9.5 8.75 10
9.5 9 9.75
9.5 9.5 9.5
9.5 9.75 9.25
9.5 10 9.25
9.75 8.5 10
9.75 8.75 9.75
9.75 9 9.75
9.75 9.25 9.5
9.75 9.75 9.25
9.75 10 9
10 8.25 10
10 8.75 9.75
10 9 9.5
10 9.25 9.5
10 9.5 9.25
10 10 9
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> W;          
vector<int> RemainW;    
vector<double> X;       
int LowerBound;         
int UpperBound;         

void Diem(int k, int CurrentSum) {
    for (int i = 1; i <= 40; i++) {
        int NewSum = CurrentSum + i * W[k];
        int MaxPotential = NewSum + 40 * RemainW[k + 1];
        int MinPotential = NewSum + 1 * RemainW[k + 1];
        if (MaxPotential < LowerBound || MinPotential >= UpperBound) {
            continue; 
        }

        X[k] = i * 0.25;

        if (k == n) {
            if (NewSum >= LowerBound && NewSum < UpperBound) {
                for (int j = 1; j <= n; j++) {
                    cout << X[j] <<" ";
                }
                cout << "\n";
            }
        } else {
            Diem(k + 1, NewSum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if (n==0) return 0;
    W.resize(n + 1);
    X.resize(n + 1);
    RemainW.assign(n + 2, 0); 

    for (int k = 1; k <= n; k++) {
        cin >> W[k];
    }

    double diem;
    cin >> diem;
    int x = round(diem * 10.0);
    LowerBound = x*40 - 20;
    UpperBound = x*40 + 20;

    for (int k = n; k >= 1; k--) {
        RemainW[k] = RemainW[k + 1] + W[k];
    }
    Diem(1, 0);

    return 0;
}
