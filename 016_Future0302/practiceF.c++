#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int n,q; //n:数列の長さ, q:クエリの数
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n){
      cin >> a[i];
    }
    //セグメントツリーの構築
    vector<int> st(4*n);
    function<int(int,int,int,int,int)> construct = [&](int k, int l, int r, int i, int x){
      if(r-l==1){
        return st[k] = x;
      }
      int m = (l+r)/2;
      if(i<m){
        return st[k] = construct(2*k+1,l,m,i,x);
      }
      else{
        return st[k] = construct(2*k+2,m,r,i,x);
      }
    };
    rep(i,n){
      construct(0,0,n,i,a[i]);
    }
    //クエリの処理
    rep(i,q){
      //クエリの種類
      int t;
      cin >> t; //1:値の更新, 2:最大値から２番目に大きな値の要素数を求める
      if(t==1){
        int p,x;
        cin >> p >> x;
        construct(0,0,n,p-1,x);
      }
      else{
        int l,r; //l以上r未満の区間
        cin >> l >> r; //1-indexed
        //mapとsetを使って、区間の最大値から２番目に大きな値の要素数を求める
        map<int,int> m;
        set<int> s;
        function<void(int,int,int,int,int)> query = [&](int k, int l, int r, int a, int bb){ //k:節点の番号, [l,r):節点の対応する区間, [a,bb):クエリの区間
          if(bb<=l || r<=a){ //節点の区間がクエリの区間と交わらない
            return;
          }
          if(a<=l && r<=bb){  //節点の区間がクエリの区間に完全に含まれる
            m[st[k]]++; //節点の値をカウント
            s.insert(st[k]); //節点の値を追加
            //debug
            cout << "st[k] " << st[k] << endl;
            return;
          }
          query(2*k+1,l,(l+r)/2,a,bb);  //左の子に対するクエリ
          query(2*k+2,(l+r)/2,r,a,bb);  //右の子に対するクエり
        };
        query(0,0,n,l-1,r); //クエリの実行
        //２番目に大きな値の個数を求める
        int ans = 0;
        if(s.size()>=2){ //２番目に大きな値が存在する
          auto it = s.end();
          it--;
          it--;
          ans = m[*it];
        }
        cout << ans << endl;
      }
    }
    return 0;
}