#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int Q;
    cin >> Q;
    vector<ll> queryer;
    int size = 0;
    for(int i=0; i<Q; i++){
        int kind;
        ll num;
        cin >> kind >> num;
        if(kind==1){
            queryer.push_back(num);
            size++;
        }else if(kind==2){
            cout << queryer[size-num] << endl;
        }
    }
    return 0;
}