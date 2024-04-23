#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //人数
    vector<int> a(n); //人数分の配列
    rep(i, 0, n-1) cin >> a[i]; //配列に値を入れる
    int ans = 0;
    rep(i, 0, n-1) ans += a[i]; //配列の合計を求める
    cout << ans*(-1) << endl; //合計を出力
    return 0;
}