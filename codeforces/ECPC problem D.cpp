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

vector<int> Stack;
int scc;
 vector<int>adj[100005];
 vector<ll>vv;
 ll mp[100005];
 ll mn[100005];

 void dfs(int node,ll intime)
 {
	 
	 ll x = mn[node];

	 for (int i = 0; i < sz(adj[node]); i++)
	 {
		 int ch = adj[node][i];
		ll w = intime+x + ((mp[ch] - x) * 2);
		if (sz(adj[ch]) == 0)
		{
			vv.push_back(w);
		}
		 dfs(ch,w);
	 }

 }
  
 void Scc(int n)
 {
	 
	 for (int i = 0; i <= n; i++)
	 {
		 adj[i].clear();
		 mn[i] = 0;
		 mp[i] = 0;
	 }
	 vv.clear();
 }

int main(){
	int u; ll v, tp = 0;
	int  t;
	cin >> t;
	while (t--){
		cin >> n;
		Scc(n);
		for (int i = 2; i <= n; i++)
		{
			cin >> u >> v;
			adj[u].push_back(i);
				mp[i] = v;
		}
		for (int i = 1; i <= n; i++)
		{
			ll MIN = 1e13;
				for (int j = 0; j < sz(adj[i]); j++)
				{
					MIN = min(mp[adj[i][j]], MIN);
				}
				mn[i] = MIN;
			
		}
		dfs(1, 0);
		sort(all(vv));
		int q;
		cin >> q;

		for (int i = 0; i < q; i++)
		{
			cin >> v;
			int x = upper_bound(vv.begin(), vv.end(), v) - vv.begin();
			cout << x<< endl;
		}
	}
}
