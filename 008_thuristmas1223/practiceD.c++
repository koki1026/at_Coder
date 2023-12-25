#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,m;
    cin >> n >> m;
    multiset<ll> r_set;
    for(i=0;i<n;i++){
      ll c; cin >> c;
      r_set.insert(c);
    }
    vector<ll> r_plus(n);
    int tmp = 0;
    for(i=0;i<n;i++){
      tmp += *r_set.begin();
      r_set.erase(r_set.begin());
      r_plus[i] = tmp;
    }

    for(i=0;i<m;i++){
      ll query; cin >> query;
      for(j=0;j<n;j++){
        if(r_plus[j]>query){
          cout << j << endl;
          break;
        }
        if(j==n-1){
          cout << n << endl;
        }
      }
    }

    return 0;
}