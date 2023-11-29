#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0, k=0;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;
    string x;
    vector<bool> used(n - m + 1); //いいi(Nの配列のうち、Mがおけるような場所の先頭要素)
    queue<int> q; //いいiの番号を保存しておく
    auto check = [&](int i) {
        if (used[i]) return;
        bool ok = true; //0番目からちゃんとチェックをするので、まずはokから始まる
        for (j=0;j<m;j++){
            ok &= (s[i+j]=='#' or s[i + j] == t[j]); //okがTrueかつ、（sの[i+j]番目も条件を満たすなら）
        }
        if (ok) { //すべて探索を終えてokのままだった場合
            used[i] = true; //今後二度と探索の必要をなくして
            q.push(i); //キューにいいiを追加する
        }
    };
    for (i=0;i<n-m+1;i++) check(i);
    while(!q.empty()){ //qに入れたものが空っぽになるまで続ける
        i = q.front(); //これから探索するものを保持
        q.pop(); //保持したのでサヨナラ
        for (j=0;j<m;j++) s[i+j] = '#';
        for (j=max(i-m+1, 0);i<min(i+m-1, n-m);j++) check(j); //#の挿入によって良いiを新たに満たすようになったものがないか確認
    }

    cout << ( s == string(n, '#') ? "Yes": "No") << endl;
    return 0;
}