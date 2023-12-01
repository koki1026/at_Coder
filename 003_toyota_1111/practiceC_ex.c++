#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(int month, int day){
    string s = to_string(month) + to_string(day);
    set<char> kinds;
    for(int i=0;i<s.size();i++){
        kinds.insert(s[i]);
    }
    return (kinds.size() == 1) ? 1:0;
}

int main(){
    int i=0, j=0;
    int n; cin >> n;
    vector<int> d(n+1);
    int ans = 0;
    for(i=1;i<=n;i++) cin >> d[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=d[i];j++){
            ans += check(i,j);
        }
    }
    cout << ans << endl;
    return 0;
}