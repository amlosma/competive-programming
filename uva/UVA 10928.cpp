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

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int n, m, c = 0;
int cnt;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}
vector<pair<int, int>>adj[100 * 1000 + 8];
bool vis[1000009];

ll tp;
ll dfs(int node)
{
	ll tp = 0;
	vis[node] = 1;
	for (int i = 0; i < sz(adj[node]); i++)
	{
		if (!vis[adj[node][i].first])
		{
		
			tp = max(tp, dfs(adj[node][i].first) + adj[node][i].second);

		}
	}
	return tp;
}
vector<string>val;
template<class T> void tovector(T par)
{
	stringstream ss(par);
	string t;
	while (ss >> t)
		val.push_back(t);
}
 multimap<int, int>mp;
int main()
{
	fast();
	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		string s;
		int mn = 10000000;
		cin.ignore();
		for (int i = 1; i <=n; i++)
		{
			getline(cin, s);
			tovector(s);
			int w = (int)val.size();
			mn = min(mn, w);
			mp.insert({ w, i });
			val.clear();

		}
		
		bool ok = false;
		for (multimap<int, int>::iterator it = mp.begin(); it != mp.end();it++)
		{
			if (it->first == mn&&ok)
				cout << " " << it->second;
			else if (it->first==mn)
				cout << it->second;
			ok = true;
		}
		cout << '\n';
		mp.clear();
		val.clear();
	}
	
}
