#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

//木でやるダイクストラ法
//disは、すべて-1で初期化している。到達できないところは-1でっせ。
vector<int> dsy(vector<int>dis,vector<vector<pair<int,int>>> g,int start,int goal){
    int n=dis.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    dis[start]=0;
    Q.push(make_pair(0,start));

    while(!Q.empty()){
        int pos=Q.top().second;Q.pop();
        for(int i=0;i<g.at(pos).size();i++){
            int to=g.at(pos).at(i).first;
            int cost=g.at(pos).at(i).second;
            if(dis[to]==-1||dis[to]>dis[pos]+cost){
                dis[to]=dis[pos]+cost;
                Q.push(make_pair(dis[to],to));
            }
        }
    }
    return dis;
}

int64_t dss(vector<int64_t>dis,vector<vector<pair<int64_t,int64_t>>> g,int64_t start,int64_t goal){
    int n=dis.size();
    priority_queue<pair<int64_t,int64_t>,vector<pair<int64_t,int64_t>>,greater<pair<int64_t,int64_t>>> Q;
    dis[start]=0;
    Q.push(make_pair(0,start));

    while(!Q.empty()){
        int pos=Q.top().second;Q.pop();
        for(int i=0;i<g.at(pos).size();i++){
            int to=g.at(pos).at(i).first;
            int cost=g.at(pos).at(i).second;
            if(dis[to]==-1||dis[to]>dis[pos]+cost){
                dis[to]=dis[pos]+cost;
                Q.push(make_pair(dis[to],to));
            }
        }
    }
    return dis[goal];
}

int main(){
    int64_t n,m,s,t; cin>>n>>m>>s>>t;
    int64_t money=pow(10,15);

    vector<vector<pair<int64_t,int64_t>>>gy(n),gs(n);
    vector<int64_t> dis(n,-1);
    vector<int64_t> dis2(n,-1);

    for(int i=0;i<m;i++){
        int u,v,a,b;
        cin>>u>>v>>a>>b;
        gy.at(u-1).push_back(make_pair(v-1,a));
        gy.at(v-1).push_back(make_pair(u-1,a));
        gs.at(u-1).push_back(make_pair(v-1,b));
        gs.at(v-1).push_back(make_pair(u-1,b));
    }

    dis=dsy(dis,gy,s-1,t-1);//sから各国への円の合計
    dis2=dsy(dis2,gs,t-1,s-1);//tから各国へのすぬけの合計
    vector<int64_t> dis_min(n);
    dis_min.at(n-1)=dis[n-1]+dis2[n-1];

    for(int i=n-2;i>=0;i--){
        dis_min[i]=min(dis[i]+dis2[i],dis_min[i+1]);
    }

    for(int i=0;i<n;i++){
        cout<<money-dis_min[i]<<endl;
    }
    
}