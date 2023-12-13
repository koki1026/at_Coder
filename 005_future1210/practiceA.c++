#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n,s,k; cin >> n >> s >> k;
    int ans = 0;
    for(i=0;i<n;i++){
      int p,q;
      cin >> p >> q;
      ans += p*q;
    }
    if(ans<s) ans += k;
    cout << ans << endl;
    return 0;
}