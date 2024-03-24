#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //要素数
    cin >> n;
    ll k; //max値
    cin >> k;
    ll max_value;
    //max_valueを、0からkまでの和で初期化
    max_value = k*(k+1)/2;
    set<ll> s;
    rep(i,0,n){
        ll a;
        cin >> a;
        if(a<=k){
            s.insert(a);
        }
    }
    //sに含まれる全要素の和を求める
    ll sum = 0;
    for(auto x : s){
        sum += x;
    }
    //max_valueからsumを引いた値を出力
    ll ans = max_value - sum;
    cout << ans << endl;
    return 0;
}