#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int i, j;
    int n;
    cin >> n;
    std::vector<int>a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    int m1;//1番目に大きい数字
    int m2;//2番めに大きい数字

    m1 = a[0];
    m2 = 0;

    for(i=0;i<n;i++){
        if(a[i] > m1){
            m2 = m1;
            m1 = a[i];
        }
        //a[i]がm1とm2の間
        else if(m1 > a[i] && a[i] > m2){
            m2 = a[i];
        }
    }
    cout << m2 << endl;
    return 0;
}