#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    bool check = true;
    int cnt = 0;
    while(check){
      if(n%2){
        check=false;
      }
      else{
        cnt++;
        n=n/2;
      }
    }
    cout << cnt << endl;
    return 0;
}