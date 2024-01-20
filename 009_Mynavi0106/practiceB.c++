#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0, k=0;
    int n;
    cin >> n;
    for(i=0;i<n;i++){
      for(j=0;j<n-i;j++){
        for(k=0;k<n-i-j;k++){
          cout << i << " " << j << " " << k << endl;
        }
        cout << i << " " << j << " " << k << endl;
      }
      cout << i << " " << j << " " << 0 << endl;
    }
    cout << i << " " << 0 << " " << 0 << endl;
    return 0;
}