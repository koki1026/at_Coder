#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n;
    string c;
    string cc = to_string(n);
    char ccc = cc[0];
    rep(i,n) c.push_back(ccc);
    cout << c << endl;
    return 0;
}