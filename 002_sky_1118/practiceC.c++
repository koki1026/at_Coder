#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans =0;
    //次の文字列と同じならカウントアップ、違ったら文字とカウントを記入し、次へ
    int cnt = 0;
    int c_index = 0;
    std::vector<int> c(26,0);
    for(i=0;i<n;i++){
        if(i==0 || s[i] == s[i-1]){
            cnt++;
        }
        else{
            c_index = s[i-1] - 'a';
            c[c_index] = std::max(c[c_index], cnt);
            cnt = 1;
        }
    }
    //最後
    c_index = s[n-1] - 'a';
    c[c_index] = std::max(c[c_index], cnt);
    
    for(i=0;i<26;i++){
        ans += c[i];
    }
    cout << ans << endl;
    return 0;
}