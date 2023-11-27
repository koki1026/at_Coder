#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i, j;
    string s;
    cin >> s;
    int s_size = static_cast<int>(s.size());
    for (i=0;i<s_size-1;i++){
        cout << s[i] << " ";
    }
    cout << s[s_size-1] << endl;
    
    return 0;
}