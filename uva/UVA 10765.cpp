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
vector<int>adj[20000],as;

vector<pair<int, int> > ans;
int low[100000], dfn[100000],ndfs;
int arr[10011];
void tarjan(int node,int par){
dfn[node] = low[node] = ++ndfs;
for (int nxt : adj[node]) {
	if (dfn[nxt] == -1) {
		tarjan(nxt, node);
		low[node] = min(low[node], low[nxt]);
		if (low[nxt] > dfn[node])
			arr[nxt]++, arr[node]++;

	}
	else if (nxt != par)
		low[node] =min(low[node], dfn[nxt]);
}
}
void Scc(int n)
{
	fill(dfn, dfn + n + 1, -1);
	fill(low, low + n + 1, -1);
	fill(arr, arr + n + 1, 0);
	ndfs = 0;
	for (int i = 0; i <= n; i++)adj[i].clear();
	ans.clear();
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	while (scanf("%d %d", &n, &m) && n != 0 && m != 0) {
		Scc(n);

		int a, b;
		while (scanf("%d %d", &a, &b) && a != -1 && b != -1) {
			adj[a].push_back(b);
			
			adj[b].push_back(a);
		}
		
		tarjan(0, -1);

		for (int i = 0; i < n; ++i) {
			if (arr[i] == adj[i].size())
				ans.push_back({ i, arr[i] });
			else if (arr[i] < adj[i].size())
				ans.push_back({ i, arr[i] + 1 });
		}

		sort(ans.begin(), ans.end(), cmp);

		for (int i = 0; i < m; ++i)
			printf("%d %d\n", ans[i].first, ans[i].second);
		puts("");
	}

	return 0;
}

