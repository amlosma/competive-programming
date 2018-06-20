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
vector<int>adj[100001];
vector<int>tosort;
bool vis[10001];
void dfs(int node)
{
	if (vis[node])
		return;
	vis[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int ch = adj[node][i];
			dfs(ch);
	}
	tosort.push_back(node);
}
int main()
{
	fast();
	int t;
	int u, v;
	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> n >> m;
		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
		}
		
		for (int j = 1; j <= n; j++)
			vis[j] = 0;
		for (int j=1; j <= n; j++)
		{
			if (!vis[j]){
				 dfs(j);
			}
		}
		for (int j = 0; j <= n; j++) vis[j] = 0;

		for (int j = sz(tosort) - 1; j >= 0;j--)
		{
			if (!vis[tosort[j]])
			{
				dfs(tosort[j]); 
				cnt++;
			}
		}
		cout << "Case " << i << ": " << cnt << endl;
		for (int j = 0; j <= n; j++) adj[j].clear();
		tosort.clear();
	}

}
