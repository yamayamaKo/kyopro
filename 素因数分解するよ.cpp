#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> soinsuu(int n){
    vector<pair<int,int>> ret;
    for(int i=2;i*i<=n;i++){
        if(n%i !=0) continue;
        int ex=0;
        while(n%i ==0){
            ex++;
            n /= i; //n変更することで、それ以降の約数で割り切れることはない
        }
        ret.push_back(make_pair(i,ex));
    }
    //nが素数だった場合
    if(n!=1) ret.push_back(make_pair(n,1));
    return ret;
}


int main(){
    int64_t n,p;
    cin >> n >> p;
    int64_t ans=1;
    auto ps=soinsuu(p);
    for(auto i:ps){
        //cout << i.first<<" "<<i.second<<endl;
        ans *= pow(i.first,(i.second/n));
    }
    cout << ans << endl;
}