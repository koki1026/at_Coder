#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //数列の長さ
    vector<int> a(n); //数列
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    //各要素を選ぶか選ばないかを全探索
    set<int> s;
    for(i=0; i<(1<<n); i++){
        int sum = 0;
        for(j=0; j<n; j++){
            if(i&(1<<j)){
                sum += a[j];
            }
        }
        s.insert(sum);
    }
    int m; cin >> m; //キューの数
    vector<int> b(m); //キュー
    rep(i,m) cin >> b[i];
    rep(i,m){
        if(s.count(b[i])){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

    return 0;
}