#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;
ll N;



// UnionFind木
struct UnionFindTree {
	// rank[x] = UnionFind木のランク
	vector<int> rank;
	// parents[x] = xの親
	vector<int> parents;
 
	UnionFindTree() {}
 
	// n個の木を作成
	UnionFindTree(int n) {
		rank.resize(n, 0);
		parents.resize(n, 0);
		for (int i = 0; i < n; i++) {
			makeTree(i);
		}
	}
 
	// xを根とする木を作成する
	void makeTree(int x) {
		parents[x] = x;
		rank[x] = 0;
	}
 
	// xとyが同じ集合にいるか。計算量はおおよそO(α(n))
	bool isSame(int x, int y) {
		return findRoot(x) == findRoot(y);
	}
 
	//xとyを同じ集合にする。計算量はおおよそO(α(n))
	bool unite(int x, int y) {
		x = findRoot(x);
		y = findRoot(y);
		if (x == y) return false;
		if (rank[x] > rank[y]) {
			parents[y] = x;
		}
		else {
			parents[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
		return true;
	}
 
	// xを含む木の根を求める
	int findRoot(int x) {
		if (x != parents[x]) {
			parents[x] = findRoot(parents[x]);  // change the x's parent to the root of tree.
		}
		return parents[x];
	}
};