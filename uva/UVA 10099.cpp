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
int vis[199999],cost[199999],tack[199999];
vector<pair<int,int>>adj[199999];
void scc(int n)
{
	fill(vis, vis + n+1, 0);
	fill(cost, cost + n+1, 0);
	for (int i = 0; i <= n; i++)adj[i].clear();
}
int main() {
	fast();
	int c, u, v, cases = 0, s, e, vall;
	while (cin>>n>>m)
	{
		if (n == 0)  break;
		scc(n);
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> c;
			adj[u].push_back({ v, c });
			adj[v].push_back({ u, c });
			
		}
		cin>>s>>e>>vall;
		queue<int>q;
		q.push(s);
		cost[s] = 0xfffffff;
		while (!q.empty())
		{
			int w = q.front();
			q.pop();
			vis[w] = 0;
			for (int i = 0; i < sz(adj[w]); i++)
			{
				if (cost[adj[w][i].first] < min(adj[w][i].second, cost[w]))
				{
					cost[adj[w][i].first] = min(adj[w][i].second, cost[w]);
					if (vis[adj[w][i].first] == 0)
					{
						vis[adj[w][i].first] = 1;
						q.push(adj[w][i].first);
					}
				}
			}
			
		}
			cost[e]--;
			cout << "Scenario #"<< ++cases << endl;;
			cout<<"Minimum Number of Trips = "<<vall / cost[e] + (vall%cost[e] != 0)<<endl<<endl;
	}
	return 0;
}
