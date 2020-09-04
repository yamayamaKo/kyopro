#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
//#define SAMPLE 1000000
using namespace std;
//using P=pair<int,int>;
//using M=map<int,int>;
//using ll=long long;
 
int main(){
    int n; 
    cin >> n;
    vector<int> A(n);
    int64_t sum=0;
    bitset<4000009> dp;
    dp.set(0,1);

    for(int i=0;i<n;i++){
        cin>>A.at(i);
        sum+=A.at(i);
        dp |= (dp<<A[i]);//先にシフト演算しておいて問題はない。
    }

    int64_t odd = sum%2;
    int64_t key=sum/2 + odd;

    for(int i=key;i<4000009;i++){
        if(dp.test(i)){
            cout << i << endl;
            return 0;
        }
    }

}