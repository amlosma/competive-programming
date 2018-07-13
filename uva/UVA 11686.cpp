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

int  vis[100001];
int ndfs;
vector<int> Stack;
int scc;
 vector<int>adj[100005];
 vector<int>vv;
 int ans = 0;
 void dfs(int node)
 {
	 vis[node] = 1;
	 for (int i = 0; i < sz(adj[node]); i++)
	 {
		 int ch = adj[node][i];
		 if (vis[ch] == 0)dfs(ch);
		 else if (vis[ch] == 1)
		 {
			 ans = 1;
			 return;
		 }
	 }
	 vv.push_back(node);
	 vis[node] = -1;

 }
  
 void Scc(int n)
 {
	 
	 for (int i = 0; i <= n; i++)
	 {
		 adj[i].clear();
	 }
	 vv.clear();
	 ans = 0;
	 fill(vis, vis + n + 1, 0);
 }
 /**/
int main(){
	int u, v;
	while (cin >> n >> m&&n&&m)
	{
		Scc(n);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]==0)dfs(i);
		}
		if (ans)
			cout << "IMPOSSIBLE\n";
		else
		{
			reverse(all(vv));
			for (auto it : vv)
				cout << it << endl;
		}
	}
}
