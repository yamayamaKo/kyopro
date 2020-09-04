#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
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
void output(vector<int> s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            cout << " ";
        cout << s[i]; //<<endl;
    }
    cout << endl;
}

int MOD = pow(10, 9) + 7;


signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];

    absSort(a);
    reverse(all(a));
    int ans = 1;
    //int key = k-1;

    vector<int> plus;
    vector<int> minus;

    //正ならプラスに追加、負ならマイナスに追加するよ
    for(int i=0;i<n;i++){
        if(a[i]>0) plus.push_back(a[i]);
        else minus.push_back(a[i]);
    }

    if(plus.size()>0){//正値が存在する
        if(n==k){//このときは、負の数が偶数個だったらいいよ。でも、n=kなら全部選ぶじゃん
            for(int i=0;i<k;i++){
                ans=(ans*(a[i])%MOD)%MOD;
            }
        }else{//このときは、常に正。負の数もうまいこと選んでいく必要あり。
            //負の数を二個ずつ選ぶ。正の数は1つずつ選ぶ。
            //checkは選んだ値の数
            int check=0;
            //この2つはそれぞれ今見るインデックス
            int plus_point=0;
            int minus_point=0;

            //k個選ぶまで続けるよ
            while(check<k){
                //残り一個のときは正の値を加えるよ
                if(check==(k-1)){
                    ans=(ans*(plus[plus_point])%MOD)%MOD;
                    k--;
                }else{
                    //残り1個ではないときは、負の値の上位2つと正の値の上位2つを比べる。
                    //ここで、全て使い切った場合や、正の値が残り1つしかない場合に注意しよう。
                    
                    int minus_score=-1;
                    int plus_score=-1;
                    //マイナスから2つ選べる場合
                    if((minus.size()-minus_point)>1){
                        minus_score=minus[minus_point]*minus[minus_point+1];
                    }
                    //プラスから2つ選べる場合
                    if((plus.size()-plus_point)>1){
                        plus_score=plus[plus_point]*plus[plus_point+1];
                    }

                    //プラスの方がいいなら、そちらを選ぶ
                    if(plus_score>minus_score){
                        ans=(ans*(plus[plus_point])%MOD)%MOD;
                        k--;
                        plus_point++;
                    }else{
                        ans=(ans*(minus_score%MOD))%MOD;
                        k-=2;
                        minus_point+=2;
                    }

                }
            }
        }
    }
    else{//正が1つもない
        if(k%2==0){//負の数を偶数個選ぶ。このときは、答えは正になるよ。
            //minusの前からk個選べばヨシ
            for(int i=0;i<k;i++){
                ans=(ans*(minus[i])%MOD)%MOD;
            }
        }else{//kが奇数。つまり、負の数を奇数個選ぶ。答えは負になるよ。
            //minusの後ろからk個選べばヨシ
            for(int i=1;i<=k;i++){
                ans=(ans*(minus[minus.size()-i])%MOD)%MOD;
            }
        }
    }

    if(ans<0) ans+=MOD;
    cout << ans << endl;

}