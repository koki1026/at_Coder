#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,l,r;
    cin >> n >> l >> r;
    rep(i,n){
      int c;
      cin >> c;
      if(c<l){
        cout << l;
      }
      else if(c>r){
        cout << r;
      }
      else{
        cout << c;
      }
      if(i!=n-1){
        cout << " ";
      }
      else{
        cout << endl;
      }
    }
    return 0;
}