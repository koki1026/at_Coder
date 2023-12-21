#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    ll b;
    cin >> b;
    ll ans = 0;
    ll a = 1;
    bool check = false;
    while(ans<b && a < 16){
      ans = 1;
      for(ll ii=0;ii<a;ii++){
        ans *= a;
      }
      if(ans==b) {
        check = true;
        break;
      }
      a++;
    }

    if(check) cout << a << endl;
    else cout << -1 << endl;
    return 0;
}