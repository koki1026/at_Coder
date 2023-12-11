#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int k,g_full,m_full;
    cin >> k >> g_full >> m_full;
    int cnt=0;
    int g_now = 0,m_now = 0;
    while(cnt<k){
      if(g_now>=g_full){
        g_now = 0;
        cnt++;
      }
      else if(m_now == 0){
        m_now = m_full;
        cnt++;
      }
      else{
        if(g_full-g_now<m_now){
          m_now -= (g_full-g_now);
          g_now=g_full;
        }
        else{
          g_now += m_now;
          m_now = 0;
        }
        cnt++;
      }
    }
    cout << g_now << " " << m_now << endl;
    return 0;
}