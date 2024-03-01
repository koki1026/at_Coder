#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int h,w,n; cin >> h >> w >> n;
    string s; cin >> s;
    set<char> st[h*w];
    rep(i,h){
        rep(j,w){
            char c; cin >> c;
            if(c=='.'){
                st[i*w+j].insert('.');
                // insert U and D and L and R (can to move)
                st[(i-1)*w+j].insert('D');
                st[(i+1)*w+j].insert('U');
                st[i*w+(j-1)].insert('R');
                st[i*w+(j+1)].insert('L');
            }
        }
    }
    
    queue<int> q;
    for(i=0;i<h*w;i++){
        if(st[i].count('.')) q.push(i);
    }
    for(i=0;i<n;i++){
        char c = s[i];
        queue<int> q2;
        if(c=='U'){
            while(!q.empty()){
                int p = q.front(); q.pop();
                if(st[p].count('U')){
                    q2.push(p-w);
                }
            }
        }else if(c=='D'){
            while(!q.empty()){
                int p = q.front(); q.pop();
                if(st[p].count('D')){
                    q2.push(p+w);
                }
            }
        }else if(c=='L'){
            while(!q.empty()){
                int p = q.front(); q.pop();
                if(st[p].count('L')){
                    q2.push(p-1);
                }
            }
        }else if(c=='R'){
            while(!q.empty()){
                int p = q.front(); q.pop();
                if(st[p].count('R')){
                    q2.push(p+1);
                }
            }
        }
        q = q2;
    }
    cout << q.size() << endl;
    return 0;
}