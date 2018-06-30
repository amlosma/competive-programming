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
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
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
/*
كُن مُشعًّا ، كُن شخصًا يُستضاءُ بهِ أملًا ، و اصنع مِن نفسك روحًا يُحبّها الله 💜
*/
vector<int>edj[10001];
int vis[100000];
int tp;
void dfs(int node)
{
	vis[node] = 1;
	tp++;
	for (int i = 0; i < sz(edj[node]); i++)
	{
		int ch = edj[node][i];
		if (!vis[ch])
			dfs(ch);

	}
}
int main() {
	fast();

	int t;
	cin >> t;
	while (t--)
	{
		int n, x, y,a,b;
		cin >> n >> x >> y;
		for (int i = 0; i <= n; i++)
			edj[i].clear();
		fill(vis, vis + n + 1, 0);
		for (int i = 0; i < x; i++)
		{
			cin >> a >> b;
			edj[a].push_back(b);
		}
		for (int i = 0; i < y; i++)
		{
			cin >> a;
			if (!vis[a])
				dfs(a);
		}
		cout << tp << endl;
		tp = 0;
	}
	
	return 0;
}
