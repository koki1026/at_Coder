#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    ll n; //最大値
    cin >> n;
    //n以下の数のうち、最大の回文立方数を求める
    ll ans = 0;
    for(ll i=1;i*i*i<=n;i++){
      ll x = i*i*i;
      string s = to_string(x);
      string t = s;
      reverse(t.begin(),t.end());
      if(s==t){
        ans = x;
      }
    }
    cout << ans << endl;
    return 0;
}