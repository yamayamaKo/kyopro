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

int n,m;

vector<int> small(vector<int> a,vector<int> b){
    int n=a.size();

    for(int i=0;i<n;i++){
        if(a[i]==b[i]) continue;
        if(a[i]<b[i]) return a;
        else return b;
    }
    //どっちも同じ
    return a;
}

vector<int> change(vector<int> s,vector<int> change){
    int n=s.size();
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        int index=change[i]-1;
        ans[index]=s[i];

        //int index=change[i]-1;
        //ans[i]=s[index];
    }

    return ans;
}

void output(vector<int> s){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        cout<<s[i];
    }
    cout<<endl;
}

signed main(){ 
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    cin>>m;
    vector<vector<int>> p(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    }

    vector<int> ans=s;
    //output(small((change(s,p[0])),s));

    for(int tmp=0;tmp<(1<<m);tmp++){
        bitset<5> bit(tmp);
        //cout<<bit<<endl;
        vector<int> num;
        for(int i=0;i<m;i++){
            if(bit.test(i)){
                num.push_back(i);
            }
        }

        int len=num.size();
        //output(num);

        if(len!=0){
            do{
                vector<int> si=s;
                for(int i=0;i<len;i++){
                    si=change(si,p[num[i]]);
                }
                ans=small(ans,si);
            }while(next_permutation(all(num)));
        }
    }

    output(ans);
}  