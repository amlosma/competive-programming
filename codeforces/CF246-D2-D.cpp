/*لا تقهر عبدا حتى لا يؤذيك عاءه*/
#include<bits/stdc++.h>
#include <stdlib.h>
#include<assert.h>
using namespace std;
#define PI 3.14159265359
#define OO 1e9
#define S second
#define F first
#define MP                  make_pair
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
#define sz(v) ( (int) (v.size()) )
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int n, m, c = 0;
int cnt, tp;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}
vector<set<int>>adj(100009,set<int>());
int vis[500009];
int color[500009];
map<int,int>arr;
int main()
{
	fast();
	int v, u, t, c; 

	cin >> c >> n;
	for (int i = 1; i <= c; i++)cin >> color[i],vis[color[i]]=1;
	for (int i = 0; i < n; i++)
	{
		cin >> v >> u;
		if (color[v] == color[u])continue;
		adj[color[v]].insert(color[u]);
		adj[color[u]].insert(color[v]);

	}
	int m = 0;
	for (int i = 1; i <=6; i++)
	{
	
			arr.insert({ i,adj[i].size()  });
	}
	int ans = -1, mx = -1;
	for (map<int, int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		if (mx < it->second&&vis[it->second])
		{
			mx = it->second;
			ans = it->first;
		}
	}
	cout << ans;
}
