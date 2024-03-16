#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //ダーツの的の数
    cin >> n;
    int m; //ダーツの目標点
    cin >> m;
    vector<ll> a(n); //ダーツの的の点数
    rep(i, 0, n){
        cin >> a[i];
    }
    a.push_back(0);
    rep(i, 0, n){
        rep(j, 0, n){
            a.push_back(a[i] + a[j]);
        }
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    rep(i, 0, a.size()){
        if(a[i] > m){
            break;
        }
        int pos = upper_bound(a.begin(), a.end(), m - a[i]) - a.begin();
        ans = max(ans, a[i] + a[pos - 1]);
    }
    cout << ans << endl;
    return 0;
}