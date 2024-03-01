#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    ll i=0, j=0;
    ll n,m; cin >> n >> m;
    ll k; cin >> k;
    ll lcm = n*m / gcd(n,m);
    cout << lcm << endl;
    i=1;
    set<ll> a;
    while(i*n<lcm){
        a.insert(i*n);
        i++;
    }
    j=1;
    while(j*m<lcm){
        a.insert(j*m);
        j++;
    }
    ll kosuu = a.size();
    cout<<kosuu<<endl;
    ll gunnsuu = k / kosuu;
    ll kousuu = k % kosuu;
    if(kousuu==0){
        kousuu;
        gunnsuu--;
    }
    ll ans_g = gunnsuu*lcm;
    auto it = a.begin();
    advance(it, kousuu-1); // i番目の要素にイテレータを移動
    cout << *it << endl; // i番目の要素を出力
    ll ans_k = *it;
    ll ans = ans_g + ans_k;
    cout << ans << endl;
    return 0;
}