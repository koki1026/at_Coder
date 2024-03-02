#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)
typedef pair<int, int> P;

int main(){
    int i=0, j=0;
    int m; cin >> m; //星座に含まれる星の数
    vector<P> a(m); //星の座標
    for(i=0; i<m; i++){
        cin >> a[i].first >> a[i].second;
    }
    int n; cin >> n; //登場する星座の数
    vector<P> b(n); //星座の座標
    for(i=0; i<n; i++){
        cin >> b[i].first >> b[i].second;
    }
    //それぞれソート
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    //星座の座標を全ての星の座標に対して動かして、一致するかどうかを調べる
    for(i=0; i<n; i++){
        int x = b[i].first - a[0].first;
        int y = b[i].second - a[0].second;
        bool flag = true;
        for(j=0; j<m; j++){
            P p = make_pair(a[j].first + x, a[j].second + y);
            if(binary_search(b.begin(), b.end(), p)){
                continue;
            }else{
                flag = false;
                break;
            }
        }
        if(flag){
            cout << x << " " << y << endl;
            return 0;
        }
    }
    return 0;
}