#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    ll n;
    cin >> n;
    n--;
    vector<ll> c;
    while(n>4){
      c.push_back((n%5)*2);
      n=n/5;
    }
    c.push_back(n*2);
    for(i=0;i<c.size();i++){
      cout << c[c.size()-i-1];
    }
    cout << endl;
    return 0;
}