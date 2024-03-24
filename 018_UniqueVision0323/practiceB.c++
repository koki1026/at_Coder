#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,n) for (int i=a;i<(n);++i)

int main(){
    int i=0, j=0;
    int w,b; //白鍵の数,黒鍵の数
    cin >> w >> b;
    while(w>=7 && b>=5){
        w -= 7;
        b -= 5;
    }
    if(w==0 && b==0){
        cout << "Yes" << endl;
        return 0;
    }
    w_hozon = w;
    b_hozon = b;
    int count = w+b;
    vector<char> v = {'W','B','W','B','W','W','B','W','B','W','B','W'};
    rep(i,0,12){
        w = w_hozon;
        b = b_hozon;
        rep(j,0,count){
            if(v[(i+j)%12]=='W'){
                w--;
            }else{
                b--;
            }
        }
        if(w==0 && b==0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}