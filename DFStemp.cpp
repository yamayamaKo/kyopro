#include <bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;
using grid=vector<vector<int>>;

//深さ優先
vector<bool> seen;
vector<int> first_order;//行き掛け
vector<int> last_order;//帰りがけ

//普通の深さ優先探索seenを返す感じ
void dfs(const Graph &G,int v){
    seen[v] = true; //v探索済み

    for(auto next_v :G[v]){
        if(seen[next_v])continue;//もう探索していた
        dfs(G,next_v);
    }
}

//行き掛け、帰りがけ入手
void dfs_fl(const Graph &G,int v,int& first,int& last){
    seen[v] = true; //v探索済み
    first_order[v]=first++;

    for(auto next_v :G[v]){
        if(seen[next_v])continue;//もう探索していた
        dfs_fl(G,next_v,first,last);
    }

    last_order[v]=last++;
}

//タイムスタンプ取得
void dfs_timestamp(const Graph &G,int v,int& time){
    seen[v] = true; //v探索済み
    first_order[v]=time++;

    for(auto next_v :G[v]){
        if(seen[next_v])continue;//もう探索していた
        dfs_timestamp(G,next_v,time);
    }

    last_order[v]=time++;
}

//木上の探索
// v: 現在探索中の頂点、p: v の親 (v が根のときは -1)
void dfs(const Graph &G, int v, int p) {
    for (auto nv : G[v]) {
        if (nv == p) continue; // nv が親 p だったらダメ
        dfs(G, nv, v); // v は新たに nv の親になります
    }
}

//グリッドDFS
void dfs_grid(int h, int w) {
    /*seen[h][w] = true;

    // 四方向を探索
    for (int dir = 0; dir < 4; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        // 場外アウトしたり、移動先が壁の場合はスルー
        //if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        下はダメな条件
        //if (grid[nh][nw] == '#') continue;

        // 移動先が探索済みの場合
        if (seen[nh][nw]) continue;

        // 再帰的に探索
        dfs(nh, nw);
    }*/
}

int main(){
    int n,m; cin >> n>> m;

    Graph G(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(n,false);
    dfs(G,0);//根から各頂点へ到達可能かをリストで格納
}