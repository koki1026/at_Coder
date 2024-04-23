#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //豆の数
    vector<ll> a(n); //豆のおいしさ
    vector<ll> c(n); //豆の色
    rep(i, 0, n) cin >> a[i] >> c[i];

    //各色の豆の一番不味いものをmapで管理
    map<ll, ll> m;
    rep(i, 0, n){
        if(m.count(c[i]) == 0) m[c[i]] = a[i];
        else m[c[i]] = min(m[c[i]], a[i]);
    }
    //mapのうち、一番おいしいものを取り出す
    set<ll> s;
    for(auto p : m) s.insert(p.second);
    //sの一番大きい値を取り出す
    ll ans = 0;
    auto it = s.begin();
    for(; it != s.end(); ++it)
    ans = *it;
    cout << ans << endl;

    return 0;
}