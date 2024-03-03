#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,m;
    cin >> n >> m;
    int ans = 0;
    ans = n+m;
    if(ans==0){
        cout << "1" << endl;
    }
    else{
        cout << "0" << endl;
    }
    return 0;
}