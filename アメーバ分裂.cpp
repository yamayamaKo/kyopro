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

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}
int MOD = pow(10, 9) + 7;

//アメーバを集約する関数。実装が複雑になってしまった。
//実は、変化前座標の上下左右を調べる必要はない（上から順に調べていると下から分裂してきた場合以外ありえないから）。
void syuyaku(vector<vector<int>> &after,vector<vector<int>> &initial){
    int n=after.size(),m=after[0].size();

    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(after[i][j]!=0){
                int change=after.at(i).at(j);
                initial[i+1][j]+=change;
                for(int d=0;d<4;d++){
                    after.at(i+1+dy[d]).at(j+dx[d])-=change;
                }
            }
        }
    }
    /*
    //x,yの変化量
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //各座標について調べる
            int x=j,y=i;
            if(after[y][x]==0) continue;
            for(int d=0;d<4;d++){
                //移動後の座標値=分裂前に集約する座標。
                //集約座標の周辺部を見て、その周辺部の最小値を求め、分裂後座標から引き、分裂前座標に加える。
                //この操作を繰り返すといける。
                int nx=x+dx[d],ny=y+dy[d];
                if(nx<=0 || ny<=0 || nx>=(m-1) || ny>=(n-1)) continue;

                int min_ameba=pow(10,8);

                for(int pred=0;pred<4;pred++){
                    int cx=nx+dx[pred],cy=ny+dy[pred];
                    if(cx<0||cy<0||cx>(m-1)||cy>(n-1)) continue;
                    min_ameba=min(min_ameba,after[cy][cx]);
                }
                if(min_ameba!=0){
                    for(int pred=0;pred<4;pred++){
                        int cx=nx+dx[pred],cy=ny+dy[pred];
                        if(cx<0||cy<0||cx>(m-1)||cy>(n-1)) continue;
                        after[cy][cx]-=min_ameba;
                    }
                    initial[ny][nx]+=min_ameba;
                }
            }
        }
    }*/
}


signed main() {
    int n,m; cin>>n>>m;
    vector<vector<int>> ameba(n,vector<int>(m,0));
    vector<vector<int>> inittial(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            char c; cin>>c;
            ameba[i][j]=c-'0';
    }
    }

    syuyaku(ameba,inittial);

    for(int i=0;i<n;i++){
        output_yoko(inittial[i]);
    }

}
