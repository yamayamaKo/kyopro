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


//01BFS
//edgesは重み付きグラフ
//disは、とても大きい数で初期化する必要がある
void bfs01(vector<int> dis, vector<vector<pair<int,int>>> edges, int s){
    int n = dis.size();
    dis[s] = 0;
    deque<int> que;
    que.push_back(s);

    while(que.size()){
        int i = que.front(); que.pop_front();
        for(auto [j, c] : edges[i]){
            int d = dis[i] + c;
            if(d < dis[j]){
                dis[j] = d;
                if(c){
                    que.push_back(j);
                }else{
                    que.push_front(j);
                }
            }
        }
    }
}