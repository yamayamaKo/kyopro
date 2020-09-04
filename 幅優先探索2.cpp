#include <bits/stdc++.h>
using namespace std;


int main() {
    int r,c; cin >> r >> c;
    vector<vector<int>> dis(r,vector<int>(c,-1));
    vector<vector<char>> cha(r,vector<char>(c));
    int sy,sx; cin >> sy >> sx;
    int gy, gx; cin>>gy>>gx;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char cij;
            cin>>cij;
            cha.at(i).at(j)=cij;
        }
    }

    queue<pair<int,int>> Q;
    Q.push(make_pair(sy-1,sx-1));
    dis.at(sy-1).at(sx-1)=0;

    while(dis.at(gy-1).at(gx-1)==-1){
        int y,x;//今の座標
        y=Q.front().first; x=Q.front().second;
        Q.pop();

        int dy[4]={1,0,-1,0};
        int dx[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int ey=y+dy[i];
            int ex=x+dx[i];
            if(ex<0 || ey<0) continue;
            if(cha[ey][ex]=='#'||dis[ey][ex]!=-1) continue;
            dis[ey][ex]=dis[y][x]+1;
            Q.push(make_pair(ey,ex));
        }
    }

    cout<<dis.at(gy-1).at(gx-1)<<endl;
}
