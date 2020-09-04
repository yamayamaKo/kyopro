#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define all_acc(x) (x).begin(),(x).end(),0LL
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

//mは素数じゃなくてもええで
// mod. m での a の逆元 a^{-1} を計算する
//aのmod mにおける逆元を求めてくれる
//aをmで割って、その後bの逆元を求めると分かる。
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const long long MAX=10;
long long MOD=pow(10,9)+7;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
//前処理にO(n)、計算にはO(1)かかる。
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
//上のやつとセット。これはn<10^7くらいじゃないと使えない。
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//n>=10^9とかで、kは10^7より小さいくらい
int nCk(int n,int k,int mod){
   int bunbo=1;
   int bunsi=1;
   for(int i=0;i<k;i++){
       bunbo=(bunbo*((n-i)% mod))% mod;
       bunsi=bunsi*((k-i)% mod)% mod;
   }
   int bunsi_inv=modinv(bunsi,mod);
   return ((bunbo%mod) * (bunsi_inv%mod))% mod;
}

// a ÷ b mod. MOD を計算してみる
int main() {
    //const int MOD = 1000000007;

    long long a = 12345678900000;
    long long b = 100000;

    // a を 10000000007 で割ってから b の逆元をかけて計算
    a %= MOD;
    cout << a * modinv(b, MOD) % MOD << endl;
}