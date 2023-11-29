#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n, m;
    cin >> n >> m;
    std::vector<int> a(m);
    for(i=-0;i<m;i++){
        cin >> a[i];
    }
    std::vector<int> v(n, 0);
    //最多得票の得票数とその人間を覚えておく
    int vote=0;
    int pre_tmp = 0;
    int high_score = 0;
    for(i=0;i<m;i++){
        vote = a[i]-1;
        v[vote]++;
        if(v[vote] > v[pre_tmp]){
            high_score = v[vote];
            pre_tmp = vote;
        }
        else if(v[vote] == v[pre_tmp]){
            pre_tmp = std::min(pre_tmp, vote);
        }
        cout << (pre_tmp+1) << endl;
    }
    return 0;
}