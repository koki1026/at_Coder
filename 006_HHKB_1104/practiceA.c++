#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;cin >> n;
    string s;cin >> s;
    string ans = "No";
    rep(i,n-1){
      if(s[i]=='a'){
        if(s[i+1]=='b') ans = "Yes";
      }
      else if(s[i]=='b'){
        if(s[i+1]=='a') ans = "Yes";
      }
    }
    cout << ans << endl;
    return 0;
}