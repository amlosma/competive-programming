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
vector<int>adj[100009];
int vis[50009];
void dfs(int node)
{
	vis[node] = cnt;

	for (int i = 0; i <sz(adj[node]); i++)
	{
		int ch = adj[node][i];
		if (vis[ch]!=cnt)
		{
		     tp++;
			dfs(ch);
		}
	}
	
}

int main()
{
	fast();
	int v, u, t,c=0; cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> v >> u;
			adj[v].push_back(u);
		}
		int m = 0, mx = -1;
		for (int i = 1; i <= n; i++)
		{
			
			if (vis[i]==0)
			{
				tp = 0;
				cnt ++;
				dfs(i);
				if (tp > mx)
				{
					mx = tp;
					m = i;
				}
				
				
			}
		}
		cout << "Case " << ++c << ": " << m << endl;
		for (int i = 0; i <= n; i++)adj[i].clear();
		for (int i = 0; i <= n; i++)for (int j = 0; j <= n; j++)vis[i] = 0;
	}
}
