#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
    int i=0, j=0;
    int H,W;
    cin >> H >> W;
    //行動回数
    int N;
    cin >> N;
    //初期位置
    int a,b;
    a=0;b=0;
    vector<vector<bool>> map(H,vector<bool>(W,false));
    //現在の向き
    int direction=0;//0:上向き,1:右向き2:下向き3:左向き
    //自分のマスがFalseならTrueにした後向かって右に、TrueならFalseにした後向かって左に進む
    rep(i,N){
        if(map[a][b]==false){
            map[a][b]=true;
            direction+=1;
            direction%=4;
            if(direction==0){
                a--;
                if(a<0){
                  a=H-1;
                }
            }else if(direction==1){
                b++;
                if(b>=W){
                  b=0;
                }
            }else if(direction==2){
                a++;
                if(a>=H){
                  a=0;
                }
            }else{ 
                b--;
                if(b<0){
                  b=W-1;
                }
            }
        }else{
            map[a][b]=false;
            direction+=3;
            direction%=4;
            if(direction==0){
                a--;
                if(a<0){
                  a=H-1;
                }
            }else if(direction==1){
                b++;
                if(b>=W){
                  b=0;
                }
            }else if(direction==2){
                a++;
                if(a>=H){
                  a=0;
                }
            }else{ 
                b--;
                if(b<0){
                  b=W-1;
                }
            }
        }
    }
    rep(i,H){
        rep(j,W){
            if(map[i][j]==true){
                cout << "#";
            }else{
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}