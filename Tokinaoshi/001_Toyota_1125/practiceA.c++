#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,m;
    cin >> n >> m;
    int answer=0;
    rep(i,n){
      int c;
      cin >> c;
      if(c>=m) answer++;
    }
    cout << answer << endl;
    return 0;
}