#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll i=0, j=0;
    ll n; cin >> n;
    //登場する数字の種類と個数を全て管理→各数字に対する自分より上の総和を先に求める
    vector<ll> size((1e6)+1,0);
    vector<ll> my_up((1e6)+1, 0);
    ll full_max = 0; //総和
    vector<int> order(n);
    for(i=0;i<n;i++){
        ll c; cin >> c;
        size[c]++;
        order[i] = c;
        full_max += c;
    }
    for(i=0;i<size.size();i++){
        if(size[i]>0){
          full_max -= i * size[i];
          my_up[i] = full_max;
        }
    }
    for(i=0;i<n;i++){
        cout << my_up[order[i]];
        if(i<n-1) cout << " ";
    }
    cout << endl;
    return 0;
}