#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n;
    cin >> n;
    string ans;
    ans.push_back('L');
    for(i=0;i<n;i++){
      ans.push_back('o');
    }
    ans.push_back('n');
    ans.push_back('g');
    cout << ans << endl;
    return 0;
}