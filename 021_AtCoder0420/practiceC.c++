#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n; //配列の要素数
    vector<int> a(n+1); //配列
    vector<int> locate(n+1); //配列の要素の位置
    rep(i,0,n){
        cin >> a[i+1];
        locate[a[i+1]] = i+1;
    }
    //aの中身が数字じゅんにソートされるような入れ替え操作を保存していく
    vector<pair<int, int>> ans;
    int cnt = 0;
    rep(i,1,n+1){
        if(a[i] == i){
            continue;
        }
        int j = locate[i];
        swap(a[i], a[j]);
        locate[a[i]] = i;
        locate[a[j]] = j;
        ans.push_back({i, j});
        cnt++;
    }
    cout << cnt << endl;
    rep(i,0,cnt){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}