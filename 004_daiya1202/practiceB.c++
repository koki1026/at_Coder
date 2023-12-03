#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n;
    float s, m, l;
    cin >> n >> s >> m >> l;
    //一個あたりを計算する。
    float s_a, m_a, l_a;
    s_a = s/6.0;
    m_a = m/8.0;
    l_a = l/12.0;
    int tmp;
    int tmp2;
    int kosuu;
    int nedann;
    int nokori;
    if(l_a<m_a){
      if(l_a < s_a){
        tmp = 3;
      }
      else tmp = 1;
    }
    else if(m_a<s_a){
      tmp = 2;
    }
    else tmp = 1;
    cout << tmp << endl;
    if(tmp==1){
      kosuu = n/6;
      nedann = kosuu*s_a;
      nokori = n-kosuu;
    }
    else if(tmp==2){
      kosuu = n/8;
      nedann = kosuu*m_a;
      nokori = n-kosuu;
    }
    else if(tmp==3){
      kosuu = n/12;
      nedann = kosuu*l_a;
      nokori = n-kosuu;
    }

    if(nokori<12){
      nedann += min({s_a+s_a, m_a+m_a , s_a+m_a, l_a});
    }
    else if(nokori<8){
      nedann += min({s_a+s_a, m_a, l_a});
    }
    else if(nokori<6 && nokori > 0){
      nedann += min({s_a, m_a, l_a});
    }
    cout << nedann << endl;
    return 0;
}