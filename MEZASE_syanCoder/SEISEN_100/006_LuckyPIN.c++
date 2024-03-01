
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    //N:桁数 S:文字列
    int N;
    cin >> N;
    string S;
    cin >> S;
    //0~9の数字3つからなる文字列を全探索
    int ans = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                string t = to_string(i) + to_string(j) + to_string(k);
                int pos = 0;
                for(int l=0; l<N; l++){
                    if(S[l]==t[pos]) pos++;
                    if(pos==3) break;
                }
                if(pos==3) ans++;
            }
        }
    }
    //重複を許さず3つ選んだときの個数を出力
    cout << ans << endl;
    return 0;
}