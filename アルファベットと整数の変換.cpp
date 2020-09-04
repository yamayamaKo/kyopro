#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

//整数を受け取り、26進数にして返す関数.smallは小文字か大文字か
string IntTo26(int n,bool small){
    string ans="";
    char key;
    if(small){
        key='a';
    }else{
        key='A';
    }
    while(n>0){
        n--;
        int r=n%26;
        ans+=key+r;
        n/=26;
    }

    reverse(all(ans));
    return ans;
}

//小文字、大文字が順になってる場合。
string IntTo52(int n){
    string ans="";
    char big='A';
    char sma='a';
    while(n>0){
        n--;
        int r=n%52;
        if(r>=26){
            ans+=big+(r-26);
        }else{
            ans+=sma+r;
        }
        n/=52;
    }

    reverse(all(ans));
    return ans;
}

signed main(){ 
    int n; cin>>n;
    string ans=IntTo26(n,false);

    cout<<ans<<endl;
    cout<<IntTo52(n)<<endl;
}  