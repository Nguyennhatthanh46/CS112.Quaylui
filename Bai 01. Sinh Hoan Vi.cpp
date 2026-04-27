/*MÔ TẢ BÀI TOÁN

Cho số nguyên dương n, dãy sinh n! hoán vị của n số nguyên dương đầu tiên.

Input:

 - một số nguyên dương n. (1 ≤ n ≤ 9)

Output

-  n! dòng, mỗi dòng chứa n số nguyên dương là danh sách các hoán vị của n số nguyên dương đầu tiên, các số cách nhau bởi 1 khoảng trắng

Ví dụ:

Input
3
	
Output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/


#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> X;
vector<bool> used;

void KetQua(){
    for(int i = 1; i <=n; i++){
        cout<<X[i]<<" ";
    }
    cout<<"\n";
}

void HoanVi(int i){
    for(int j = 1; j <=n; j++){
        if(used[j]==0){
            X[i] = j;
            used[j] = 1;
            
            if(i == n){
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
    X.resize(n+1);
    used.assign(n+1,0);
    HoanVi(1);
}
