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
ll cnt, tp;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}
int vis[1001001];
vector<ll>adj[100001];
ll arr[100001];
void dfs(int node)
{
	
	if (vis[node])return ;
	vis[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];
		cnt = min(arr[child], cnt);
		dfs(child);
	}
}

int main()
{
	int x,y, q;
	cin >> n >> m ;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll tp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			cnt = arr[i];
			dfs(i);
			tp += cnt;
		}
	}
	cout << tp;
}
