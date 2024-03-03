#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //順列の長さ
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    //順列を生成
    vector<int> a(n);
    rep(i,n) a[i] = i+1;
    int x,y; //pとqの順列の番号
    int cnt = 0;
    //全通り試す
    do{
        bool flag = true;
        rep(i,n) if(a[i]!=p[i]) flag = false;
        if(flag) x = cnt; //pの順列の番号
        flag = true;
        rep(i,n) if(a[i]!=q[i]) flag = false;
        if(flag) y = cnt; //qの順列の番号
        cnt++;
    }while(next_permutation(a.begin(), a.end()));
    cout << abs(x-y) << endl;
    return 0;
}