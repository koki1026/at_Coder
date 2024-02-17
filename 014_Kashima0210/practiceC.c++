#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0;i<(n);++i)

int main(){
  int high_and_low(int num, int qty_1, int qty_2, int type, int ans){
    if(type==0){
      if(num == 2){
        ans += qty_1*2;
        return ans;
      }
      else{
        ans += num*qty_1;
        if(num%2==0){
          num = num/2;
          qty_1 = qty_1*2;
          qty_2 = qty_2*2;
          type = 0;
          return ans + high_and_low(num, qty_1, qty_2, type, ans);
        }else{
          if((num/2)%2==0){
            num = num/2;
            qty_1 = qty_1;
            qty_2 = qty_1;
            type = 1;
            return ans + high_and_low(num, qty_1, qty_2, type, ans);
          }else{
            num = num/2+1;
            qty_1 = qty_1;
            qty_2 = qty_1;
            type = 2;
            return ans + high_and_low(num, qty_1, qty_2, type, ans);
          }
        }
      }
    }
    else if(type==1){
      ans += num*qty_1;
      ans += (num+1)*qty_2;
      if(num%2==0){
        num = num/2;
        qty_1 = qty_1+qty_2;
        qty_2 = qty_2;
        type = 1;
        return ans + high_and_low(num, qty_1, qty_2, type, ans);
      }else{
        num = num/2+1;
        qty_1 = qty_1+qty_2;
        qty_2 = qty_2;
        type = 2;
        return ans + high_and_low(num, qty_1, qty_2, type, ans);
      }
    }
    else if(type==2){
      if(num == 2){
        ans += qty_2;
        return ans;
      }
      else{
        ans += (num-1)*qty_1;
        ans += num*qty_2;
        if(num%2==0){
          num = num/2;
          qty_1 = qty_1;
          qty_2 = qty_1 + qty_2;
          type = 2;
          return ans + high_and_low(num, qty_1, qty_2, type, ans);
        }else{
          num = num/2-1;
          qty_1 = qty_1;
          qty_2 = qty_1 + qty_2;
          type = 1;
          return ans + high_and_low(num, qty_1, qty_2, type, ans);
        }
      }
    }
  }


  int i=0, j=0;
  int N;
  cin >> N;
  int ans=0;
  ans = high_and_low(N, 1, 1, 0, 0);
  cout << ans << endl;
  return 0;
}