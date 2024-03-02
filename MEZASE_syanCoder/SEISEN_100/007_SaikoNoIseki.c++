#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for(i=0;i<n;i++){
      cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    int ans=0;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
        int x1 = p[i].first; int y1 = p[i].second;
        int x2 = p[j].first; int y2 = p[j].second;
        int dx = x2 - x1;
        int dy = y2 - y1;
        pair<int, int> p3 = make_pair(x1+dy, y1-dx);
        pair<int, int> p4 = make_pair(x2+dy, y2-dx);
        if(binary_search(p.begin(), p.end(), p3) && binary_search(p.begin(), p.end(), p4)){
          ans = max(ans, dx*dx+dy*dy);
        }
      }
    }
    cout << ans << endl;
    return 0;
}