/*
Cho một chuỗi s, hãy tìm tất cả các cách chia chuỗi s thành các chuỗi con sao cho tất cả chuỗi con đều là chuỗi đối xứng (palindrome)

INPUT

Chuỗi s không chứa khoảng trắng, không quá 100 ký tự.

OUTPUT

Với mỗi cách chia chuỗi s thành những chuỗi con, xuất ra các chuỗi con này trên cùng một dòng cách nhau bởi khoảng trắng. Các chuỗi con phải được xuất theo đúng thứ tự chúng xuất hiện trong chuỗi s. Thứ tự xuất các cách chia là không quan trọng, hệ thống chấm được hết)

VÍ DỤ
Input
aab

Output
aa b
a a b
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int n;
vector<string> Chuoi;

bool DX(int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}


void backtrack(int i) {
    if (i == n) {
        for (int j = 0; j < Chuoi.size(); j++) {
            cout << Chuoi[j] <<(j == Chuoi.size() - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    for (int end = i; end < n; end++) {
        if (DX(i, end)) {
            Chuoi.push_back(s.substr(i, end - i + 1));
            backtrack(end + 1);
            Chuoi.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
        n = s.length();
        backtrack(0);
    return 0;
}
