#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int A,B,D;//A:初項B:末項D:公差
    cin >> A >> B >> D;
    for(int i=A; i<=B; i+=D){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}