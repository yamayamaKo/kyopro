#include <bits/stdc++.h>
using namespace std;

//幅優先探索
//disは各座標への距離。行けない場合は-1にしている。
//chaは各座標の情報。文字で格納している。'X'は行けないところ。
//sはスタートの座標
//gはゴールの座標
int bfs(vector<vector<int>> dis,vector<vector<char>>cha,pair<int,int>s,pair<int,int>g){
    int h=dis.size();
    int w=dis.at(0).size();

    queue<pair<int,int>> Q;
    Q.push(s);
    dis.at(s.first).at(s.second)=0;

    while(dis.at(g.first).at(g.second)==-1 && Q.size()!=0){
        int y,x;//今の座標
        y=Q.front().first; x=Q.front().second;
        Q.pop();

        int dy[4]={1,0,-1,0};
        int dx[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int ey=y+dy[i];
            int ex=x+dx[i];
            if(ex<0||ey<0||ex>=w||ey>=h) continue;
            if(cha[ey][ex]=='X'||dis[ey][ex]!=-1) continue;
            dis[ey][ex]=dis[y][x]+1;
            Q.push(make_pair(ey,ex));
        }
    }

    return dis.at(g.first).at(g.second);
}

//幅優先探索
//disは各座標への距離。行けない場合は-1にしている。
//chaは各座標の情報。文字で格納している。'.'はすすめる。'#'は壁(黒)。
//sはスタートの座標
//gはゴールの座標
vector<vector<int>> bfs_sirokuro(vector<vector<int>> dis,vector<vector<char>>cha,pair<int,int>s,pair<int,int>g){
    int h=dis.size();
    int w=dis.at(0).size();

    queue<pair<int,int>> Q;
    Q.push(s);
    dis.at(s.first).at(s.second)=0;

    while(dis.at(g.first).at(g.second)==-1 && Q.size()!=0){
        int y,x;//今の座標
        y=Q.front().first; x=Q.front().second;
        Q.pop();

        int dy[4]={1,0,-1,0};
        int dx[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int ey=y+dy[i];
            int ex=x+dx[i];
            if(ex<0||ey<0||ex>=w||ey>=h) continue;
            if(cha[ey][ex]=='#'||dis[ey][ex]!=-1) continue;
            dis[ey][ex]=dis[y][x]+1;
            Q.push(make_pair(ey,ex));
        }
    }

    return dis;
}

int n;
//int h=n; int w=n;
set<string> ans;
vector<vector<string>> grid(n,vector<string>(n));

void search(pair<int,int> now_point,string now_string,set<pair<int,int>> visited){
    if(now_string.size()==6) ans.insert(now_string);
    else{
        ans.insert(now_string);
        int hi=now_point.first; int wi=now_point.second;

        int dy[4]={1,0,-1,0};
        int dx[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int next_h=hi+dy[i];
            int next_w=wi+dx[i];
            if(next_h<0||next_w<0||next_w>=n||next_h>=n){
                ans.insert(now_string);
            }else if(visited.count(make_pair(next_h,next_w))==1){
                ans.insert(now_string);
            }else{
                visited.insert(make_pair(next_h,next_w));
                search(make_pair(next_h,next_w),now_string+grid[next_h][next_w],visited);
            }
        }
    }
}

int main(){
    int h,w,n; cin>>h>>w>>n;
    vector<vector<int>>dis(h,vector<int>(w,-1));
    vector<vector<char>>cha(h,vector<char>(w));
    vector<pair<int,int>> fac(n);
    pair<int,int> start;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char ch;
            cin >> ch; cha.at(i).at(j)=ch;
            if(ch!='X'&&ch!='.'){
                if(ch!='S'){
                    fac.at((ch-'0')-1)=(make_pair(i,j));
                }else{
                    start=make_pair(i,j);
                }
            }
        }
    }

    int result=0;

    for(int i=0;i<n;i++){
        pair<int,int> goal=fac.at(i);
        result+=distance(dis,cha,start,goal);
        start=goal;
    }

    cout << result << endl;
}