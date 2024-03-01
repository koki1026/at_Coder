#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //S:文字列
    string S; cin >> S;
    //Sの各文字を先頭にループ
    int ans = 0;
    for(int i=0; i<S.size(); i++){
        int cnt = 0;
        for(int j=i; j<S.size(); j++){
            if(S[j]=='A' || S[j]=='T' || S[j]=='G' || S[j]=='C') cnt++;
            else break;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}