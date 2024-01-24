#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,q;
    cin >> n >> q;
    set<ll> mex_candidate;
    vector<ll> a(n+1);
    map<ll,ll> aru;
    rep(i,n+10){
      mex_candidate.insert(i);
    }
    rep(i,n){
      ll c;
      cin >> c;
      a[i+1]=c;
      aru[c]++;
      mex_candidate.erase(c);
    }
    //クエリ処理
    rep(i,q){
      ll c1,c2;
      cin >> c1 >> c2;
      aru[a[c1]]--;
      if(aru[a[c1]]==0){
        mex_candidate.insert(a[c1]);
      }
      a[c1] = c2;
      aru[a[c1]]++;
      mex_candidate.erase(a[c1]);
      cout << *mex_candidate.begin() << endl;
    }
    return 0;
}