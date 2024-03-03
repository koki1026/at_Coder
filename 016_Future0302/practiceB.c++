#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; // 1 <= n <= 100
    cin >> n; //登場する頂点の数
    vector<vector<int>> a(n); // 隣接リスト
    rep(i,n){
      rep(j,n){
        int x;
        cin >> x;
        if(x==1){
          a[i].push_back(j+1);
        }
      }
    }
    rep(i,n){
      rep(j,a[i].size()){
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
    return 0;
}