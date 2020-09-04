#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//これだとk<30までしか対応出来ないよん。ダメじゃねえか
//少し変えてみるよ
//意図せずフィボナッチを使っていたようだ
//k回再帰するときのaとbの組を返すよ。rev_gcd(k,1,0)でやればおけ
pair<int,int> rev_gcd(int k,int a,int b){
  if(k==0) return {a,b};
  if(b==0){
    return rev_gcd(k-1,a*2,a);
  }else{
    return rev_gcd(k-1,a+b,a);
  }
}