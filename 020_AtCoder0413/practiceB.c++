#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    string s; cin >> s;
    vector<int> c(26);
    for (char x : s) c[x-'a']++;
    vector<int> ans(101);
    rep(i, 0, 26) ans[c[i]]++;
    rep(i, 1, 101){
      if(ans[i]==0) continue;
      if(ans[i]==2) continue;
      else{
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
}