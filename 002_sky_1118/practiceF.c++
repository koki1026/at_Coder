#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> s(n);
    for(i=0;i<n;i++){
        int c; cin >> c;
        s[i].insert(c);
    }

    for(i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(s[a].size() > s[b].size()) swap(s[a], s[b]);
        for(int c : s[a]) s[b].insert(c);
        s[a] = {};
        cout << s[b].size() << endl;
    }
    return 0;
}