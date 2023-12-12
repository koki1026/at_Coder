#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i=0, j=0;
    int n,d;
    cin >> n >> d;
    vector<double> w(n);
    for(i=0;i<n;i++){
        double c;
        cin >> c;
        w[i] = c;
    }

    //2のn乗はシフト演算でできる
    int n2 = 1<<n;

    //平均の計算
    double ave = 0;
    for(i=0;i<n;i++){
        ave += w[i];
    }
    ave /= d;

    


    return 0;
}