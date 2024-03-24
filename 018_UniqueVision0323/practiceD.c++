#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //数列の長さ
    string s; cin >> s; //数列
    vector<ll> a(n); //コスト配列
    rep(i,0,n){
        cin >> a[i];
    }
    //数列を0101...に変換する際のコストを累積和で求めていく
    vector<ll> cost01(n+1,0);
    vector<ll> cost10(n+1,0);
    rep(i,0,n){
      if(i%2==0){
        if(s[i]=='1'){
          cost01[i+1] = cost01[i] + a[i];
          cost10[i+1] = cost10[i];
        }else{
          cost01[i+1] = cost01[i];
          cost10[i+1] = cost10[i] + a[i];
        }
      }else{
        if(s[i]=='1'){
          cost01[i+1] = cost01[i];
          cost10[i+1] = cost10[i] + a[i];
        }else{
          cost01[i+1] = cost01[i] + a[i];
          cost10[i+1] = cost10[i];
        }
      }
    }

    //とある区間を0101...で、その先を1010...に変換する際のコストを求める
    ll ans = 1e18;
    rep(i,1,n){
      ll tmp = cost01[i] + cost10[n] - cost10[i];
      ans = min(ans,tmp);
      //debug
      //cout << i << " " << tmp << endl;
    }
    //逆に、とある区間を1010...で、その先を01010...に変換する際のコストを求める
    rep(i,1,n){
      ll tmp = cost10[i] + cost01[n] - cost01[i];
      ans = min(ans,tmp);
      //cout << i << " " << tmp << endl;
    }
    cout << ans << endl;
    return 0;
}