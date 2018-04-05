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
int cnt,tp;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}
map<int, vector<int>>adj;
map<int, int>vis;
map<int, int>cost;

void dfs(char node)
{
	cost[cnt]++;
	vis[node] = cnt;
	for (int i = 0; i < sz(adj[node]); i++)
	{
		char child = adj[node][i];
		if (vis[child] == 0)
		{
			dfs(child);
		}
	}
}
int main()
{
	fast();
		int t;
	string s;
	while (cin >> t)
	{
		while (t--)
		{
			while (cin >> s&&s[0] != '*')
			{
				int u = s[1]-'A', v = s[3]-'A';
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			cin >> s;
			cnt = 0;
			for (int i = 0; i < s.size(); i += 2)
			{
				int u = s[i]-'A';
				if (vis[u] == 0)
				{
					cnt++;
					dfs(u);
				}
			}
			int tr = 0, ron = 0;
			for (map<int, int > ::iterator it = cost.begin();it!=cost.end();++it)
			{
				if (it->second != 1)
					tr++;
				else
					ron++;
			}
			cout << "There are " << tr << " tree(s) and " << ron << " acorn(s)." << endl;
			adj.clear(), vis.clear(), cost.clear();
		}
	}
}
