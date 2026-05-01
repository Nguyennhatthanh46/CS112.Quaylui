/*
Bạn Bình đi cấu hình mạng cho tiệm net. Bạn ghi tài liệu lại cho chủ tiệm nhưng do dùng phần mềm gõ văn bản quá tốt mà các dấu chấm trong chuỗi ghi địa chỉ IP của các máy bị biến mất hết. 
Hãy giúp chủ quán đoán tất cả các địa chỉ IP có thể có từ một địa chỉ IP ghi thiếu dấm chấm.

 
INPUT

Chuỗi s không quá 100 ký tự

OUTPUT

Ứng với mỗi địa chỉ IP có thể được ghi bởi chuỗi s, xuất địa chỉ IP đó ra trên một dòng. Thứ tự xuất các địa chỉ IP là không quan trọng. hệ thống chấm được hết.
Input
25525511135

	
Output
255.255.11.135
255.255.111.35
VÍ DỤ
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S;
int doDai;
vector<string> tapNghiem;

bool kiemTraOctet(string octet) {
    int len = octet.length();
    if (len == 0 || len > 3) return false;
    
    if (len > 1 && octet[0] == '0') return false; 
    
    int giaTri = stoi(octet);
    return (giaTri >= 0 && giaTri <= 255);
}


void deQuySinhIP(int chiSo, int soOctet, string ipHienTai) {
    if (soOctet == 4) {
        if (chiSo == doDai) {
            ipHienTai.pop_back(); 
            tapNghiem.push_back(ipHienTai);
        }
        return;
    }

    for (int L = 1; L <= 3; L++) {
        if (chiSo + L > doDai) break; 

        string octetTam = S.substr(chiSo, L);

        if (kiemTraOctet(octetTam)) {

            deQuySinhIP(chiSo + L, soOctet + 1, ipHienTai + octetTam + ".");
        }
    }
}

int main() {
        cin >> S;
        doDai = S.length();
        
        if (doDai >= 4 && doDai <= 12) {
            deQuySinhIP(0, 0, "");
            for (string ip : tapNghiem) {
                cout << ip << "\n";
            }
        }
    
    return 0;
}
