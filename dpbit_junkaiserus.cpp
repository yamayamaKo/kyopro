#include <iostream>
#include <bitset>
using namespace std;

const int INF = 100000000; // 十分大きな値

/* 入力 */
int N;
int dist[21][21];

/* メモ再帰 */
//この20は入力Nの最大
int dp[(1<<20) + 1][21]; // dpテーブルは余裕をもったサイズにする

//bitに対応する場所をめぐり、最後にvに行く場合の最小値
int rec(int bit, int v)
{
    // すでに探索済みだったらリターン
    if (dp[bit][v] != -1) return dp[bit][v];

    // 初期値
    if (bit == (1<<v)) {
        return dp[bit][v] = 0;
    }

    // 答えを格納する変数
    int res = INF;

    // bit の v を除いたもの
    //v桁目を0にしてアンドして吸収する
    //vの前までに行く場所
    int prev_bit = bit & ~(1<<v);

    // v の手前のノードとして u を全探索
    for (int u = 0; u < N; ++u) {
        //uがprev_bitにないとダメ
        //uのフラグが経っている=その集合にu含まれる
        if (!(prev_bit & (1<<u))) continue; // u が prev_bit になかったらダメ

        // 再帰的に探索
        if (res > rec(prev_bit, u) + dist[u][v]) {
            res = rec(prev_bit, u) + dist[u][v];
        }
    }

    return dp[bit][v] = res; // メモしながらリターン
}

int main()
{
    // 入力
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    // テーブルを全部 -1 にしておく (-1 でなかったところは探索済)
    for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

    // 探索
    int res = INF;
    for (int v = 0; v < N; ++v) {
        if (res > rec((1<<N)-1, v)) {
            res = rec((1<<N)-1, v);
        }
    }
    cout << res << endl;
}