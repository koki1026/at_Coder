#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    vector<int> yoko(n,0);
    vector<int> tate(n,0);
    vector<vector<char>> zennbu(n,vector<char>(n,'x'));
    rep(i,n){
      rep(j,n){
        char c;
        cin >> c;
        if(c=='o'){
          yoko[i]++;
          tate[j]++;
          zennbu[i][j] = 'o';
        }
      }
    }
    ll ans = 0;
    rep(i,n){
      rep(j,n){
        if(zennbu[i][j]=='o'){
          ans+=(yoko[i]-1)*(tate[j]-1);
        }
      }
    }
    cout << ans << endl;
    return 0;
}