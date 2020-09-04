#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;

int main(){
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    if(p==2||p==5){
        ll ans=0;
        for(int i=0;i<n;i++){
            if((s[i]-'0')%p==0LL){
                ans +=i+1;
            }
            
        }
        cout<<ans<<endl;
    }
    else{
        vector<ll>U(n+1,0);
        map<int,int>mods;//各mod pに何個値があるか
        mods[0]=1;
        ll ans=0;
        int pw[n+1];
        pw[0]=1;
        //この処理をしないと値が大きくなりすぎる
        for(int i=1;i<=n;i++) pw[i]=10*pw[i-1] %p;

        for(int i=n-1;i>=0;i--){
            //各Uを求める
            U[i]=(U[i+1]+(s[i]-'0')*pw[n-i-1])%p;
            ans+=mods[U[i]];
            mods[U[i]]++;
        }

        cout<<ans<<endl;
    }
}