#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, q;
    int i;
    cin >> n >> q;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }

    set<int> s; //ないものを格納する
    vector<int> cnt(n+1); //それぞれの値の度数分布
    for(i=0;i<n+1;i++){
        s.insert(i);
    }
    //度数分布表追加関数
    auto add = [&](int x){
        if(x>n) return;
        if(cnt[x]==0) s.erase(x);
        cnt[x]++;
    };
    //同じく削除関数
    auto del = [&](int x){
        if(x>n) return;
        cnt[x]--;
        if (cnt[x] == 0) s.insert(x);
    };

    //表と集合を初期化
    for (i=0;i<n;i++){
        add(a[i]);
    }

    //クエリの処理
    for (i=0;i<q;i++){
        int qi, qx;
        cin >> qi >> qx;
        qi--;
        del(a[qi]);
        a[qi]=qx;
        add(a[qi]);
        cout << *s.begin() << '\n';
    }
    return 0;
}