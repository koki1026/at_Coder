#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n,q;
    cin >> n >> q;
    string s; cin >> s;
    vector<int> cnt(n,0); //i番目にそれまでの連続の出現回数が挿入されている
    int c_cnt=0;
    for(i=1;i<n;i++){
      if(s[i]==s[i-1]){
        c_cnt++;
      }
      cnt[i] = c_cnt;
    }
    int l,r;
    for(i=0;i<q;i++){
      cin >> l >> r;
      --l;--r;
      int ans = cnt[r] - cnt[l];
      cout << ans << endl;
    }

    return 0;
}