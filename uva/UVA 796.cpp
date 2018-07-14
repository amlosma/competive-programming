#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <stdlib.h>
#include<assert.h>
using namespace std;
#define PI 3.14159265359
#define OO 1e9
#define S second
#define F first
#define MP                  make_pair
#define sz(v) ( (int) (v.size()) )
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int n, m;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}

const int MAXN =100005;
vector<int> adj[MAXN];
int ndfs, low[MAXN], dfn[MAXN], vis[MAXN];
vector<int>IS_BRIDGE[101];
void Tarjanbridge(int node, int per)
{
	vis[node] = 1;
	dfn[node] = low[node] = ++ndfs;
	for (int nxt : adj[node]) {
		if (vis[nxt] == 0) {
			Tarjanbridge(nxt, node);
			low[node] =
				min(low[node], low[nxt]);
			if (low[nxt] == dfn[nxt])
			{

				IS_BRIDGE[min(node, nxt)].push_back(max(node, nxt));
			}
		}
		else if (nxt != per)
			low[node] =
			min(low[node], dfn[nxt]);
	}
}
void Scc(int n)
{
	fill(dfn, dfn + n + 1, -1);
	fill(low, low + n + 1, -1);
	fill(vis, vis + n + 1, 0);
	for (int i = 0; i <= n; i++)
		adj[i].clear();
	
	memset(IS_BRIDGE, 0, sizeof(IS_BRIDGE));

	ndfs = 0;

}
int main() {
	int x, y, m, i, j, Case = 0; char  c;
	while (scanf("%d", &n) == 1) {
		Scc(n);
		for (i = 0; i < n; i++) {
			scanf("%d ", &x);
			cin >> c >> m >> c;
			while (m--) {
				scanf("%d", &y);
				adj[x].push_back(y);
			}
		}
		for (i = 0; i < n; i++) {
			if (vis[i] == 0) {
				
				Tarjanbridge(i,  -1);
			}
		}
		int ans = 0;
		for (i = 0; i < n; i++) {
			
			ans+=sz(IS_BRIDGE[i]);
			
		}
		printf("%d critical links\n", ans);
		for (i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
			{
				if (sz(IS_BRIDGE[i]))
				for (auto j : IS_BRIDGE[i])
				printf("%d - %d\n", i, j);
			}
		}
		puts("");
	}
	return 0;
}
