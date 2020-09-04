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
void output(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output3(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}
int MOD = pow(10, 9) + 7;


#define MAX_N 10000
#define MAX_V 60000000
#define INF 10000000000
int n, A[MAX_N], s, B[MAX_N], T[MAX_V], cur, S, m, x; bool V[MAX_N];

int minimum_cost_sort() {
	int ans = 0;
	for (int i = 0; i < MAX_V; i++) { V[i] = false; }
	for (int i = 0; i < n; i++) { B[i] = A[i]; }
	sort(B, B + n);
	for (int i = 0; i < n; i++) { T[B[i]] = i; }
	for (int i = 0; i < n; i++) {
		if (V[i] == true) { goto owata; }
		cur = i;
		S = 0;
		m = INF;
		x = 0;
		while (1) {
			V[cur] = true;
			x++;
			int v = A[cur];
			m = min(m, v);
			S += v;
			cur = T[v];
			if (V[cur]) { break; }
		}
		ans += min(S + (x - 2)*m, m + S + (x + 1)*s);
	owata:;
	}
	return ans;
}

signed main() {
	cin >> n;
	s = INF;
	for (int i = 0; i < n; i++){
		cin >> A[i];
		s = min(s, A[i]);
	}
	cout << minimum_cost_sort() << endl;
	return 0;
}