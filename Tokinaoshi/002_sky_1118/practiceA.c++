#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    string c;
    cin >> c;
    int n = c.size();
    rep(i,n){
      cout << c[i];
      if(i!=n-1) cout << " ";
      else cout << endl;
    }
    return 0;
}