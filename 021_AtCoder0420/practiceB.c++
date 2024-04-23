#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //歯の数
    int m; cin >> m; //治療回数
    vector<int> a(m); //治療回数分の歯の数
    rep(i,0,m) cin >> a[i];
    vector<bool> b(n+1, false); //歯が抜けているかどうか

    //aを取り出し、bを反転
    rep(i,0,m){
        b[a[i]] = !b[a[i]];
    }
    //falseの数を数える
    int cnt = 0;
    rep(i,1,n+1){
        if(!b[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}