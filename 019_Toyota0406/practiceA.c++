#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //ペナルティキックを蹴る回数
    //3の倍数で失敗
    rep(i, 1, n+1){
        if(i%3==0){
            cout << "x" << i;
        }else{
            cout << "o" << i;
        }
    }
    cout << endl;
    return 0;
}