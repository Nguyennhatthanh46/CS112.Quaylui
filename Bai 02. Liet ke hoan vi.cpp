/*
Cho một con số nguyên dương n chỉ bao gồm các chữ số trong khoảng từ 1 đến 9. Các chữ số bên trong số này đã được sắp xếp tăng dần. Hỏi nếu như có thể đổi chỗ các chữ số trong số n thì chúng ta sẽ thu được những số gì?

INPUT
Số nguyên dương n.

OUTPUT
Tất cả các số có thể thu được bằng cách đổi chỗ các chữ số trong n. Mỗi số ghi trên một hàng. Các số được liệt kê theo thứ tự giảm dần.

VÍ DỤ
Input 1   
589

Output 1
985
958
895
859
598
589

Input 2
4567

Output 2
7654
7645
7564
7546
7465
7456
6754
6745
6574
6547
6475
6457
5764
5746
5674
5647
5476
5467
4765
4756
4675
4657
4576
4567
*/


#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> X;
vector<bool> used;
vector<int> LuuSo;
int TongChuSo = 0;

void KetQua(){
    for(int i = 1; i <=TongChuSo; i++){
        cout<<X[i];
    }
    cout<<"\n";
}

void HoanVi(int i){
    for(int j = 1; j <=TongChuSo; j++){
        if(used[j]==0){
            X[i] = LuuSo[j];
            used[j] = 1;
            
            if(i == TongChuSo){
                KetQua();
            }
            else{
                HoanVi(i + 1);
            }
            
            used[j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int temp = n;
    for(int i = temp; i != 0; i = i/10 ){
        TongChuSo++;
    }
    X.resize(TongChuSo + 1);
    LuuSo.resize(TongChuSo + 1);
    used.assign(TongChuSo + 1,0);
    for(int i = 1; i <= TongChuSo; i++ ){
        LuuSo[i] = temp%10;
        temp = temp/10;
    }
    HoanVi(1);
}
