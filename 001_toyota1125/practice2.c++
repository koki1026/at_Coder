#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    int i;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    for(i=0; i<n; i++){
        cout << clamp(a[i], l, r) << " ";
    }
    cout << "\n";
}