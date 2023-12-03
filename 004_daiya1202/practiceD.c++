#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0;
    ll j=0, k=0;
    int n, q;
    cin >> n >> q;
    vector<string> s(n);
    vector<int> w_each(n,0);
    vector<int> h_each(n,0);
    int box_B=0;
    for (i=0;i<n;i++){
      cin >> s[i];
    }
    //まとまりの中の黒の個数を数える
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        if(s[i][j]=='B') {
          box_B++;
          w_each[i]++;
          h_each[j]++;
        }
      }
    }
    //クエリ処理
    for(i=0;i<q;i++){
      ll ans = 0;
      //端の存在とその行列数を数える
      ll a,b,c,d;
      cin >> a >> b >> c >> d;
      ll w = c-a+1;
      ll h = d-b+1;
      int w_size = w % n;
      int h_size = h % n;
      int w_start = (a+n) % n;
      int h_start = (b+n) % n;
      //ミミに含まれるBを数える
      int w_mimi = 0;
      int h_mimi = 0;
      for(j=0;j<w_size;j++){
        w_mimi += w_each[(w_start+j)%n];
      }
      ll ww_mimi = w_mimi * (h/n);
      for(j=0;j<h_size;j++){
        h_mimi += h_each[(h_start+j)%n];
      }
      ll hh_mimi = h_mimi * (w/n);

      //端を数える
      //端に含まれるBを数える
      int hasi = 0;
      int tyuu = 0;

      if(min(w_size,h_size)<min(n-w_size, n-h_size)){
        for(j=0;j<w_size;j++){
          for(k=0;k<h_size;k++){
            if(s[(w_start+j)%n][(h_start+k)%n]=='B') hasi++;
          }
        }
      }
      else{
        int w_ = (w_start+w_size)%n;
        int h_ = (h_start+h_size)%n;
        for(j=0;j<n-w_size;j++){
          for(k=0;k<n-h_size;k++){
            if(s[(w_+j)%n][(h_+k)%n]=='B') tyuu++;
          }
        }
        hasi = h_mimi+w_mimi-box_B+tyuu;
      }

      //ボックスの個数を数える
      ll box_size = (w/n)*(h/n);
      ans = (box_size*box_B) + hh_mimi + ww_mimi + hasi;
      cout << ans << endl;
    }
    return 0;
}