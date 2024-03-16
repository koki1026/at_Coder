#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; //数列の長さ
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int k; //探す数
    cin >> k;
    sort(a.begin(), a.end());
    int cnt = 0;
    rep(i,k){
        int x; //探す数
        cin >> x;
        //aにおけるxの登場回数を二分探索
        if(binary_search(a.begin(), a.end(), x)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}