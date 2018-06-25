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
vector<int>edj[1000],degedj;vector<vector<int>> comps;
int dfn[1000], low[1000], instack[1000],comp[10000];
int ndfs;
vector<int> Stack;
int scc;

void Tarjanbridge(int node, int per)
{

	dfn[node] = low[node] = ++ndfs;
	int nof = 0;
	for (int nxt : edj[node]) {
		//if (nxt == per) continue;
		if (dfn[nxt] == -1) {
			Tarjanbridge(nxt, node);
			nof++;
			low[node] = min(low[node], low[nxt]);
			if ((per == -1 && nof > 1) || (per != -1 && dfn[node] <= low[nxt])) {
				instack[node] = 1;
			}
		}
		else if (nxt != per)
			low[node] =
			min(low[node], dfn[nxt]);
	}
}
void Scc(int n)
{

	fill(dfn, dfn + n + 1, -1);
	fill(low, low + n + 1, -1);
	fill(instack, instack + n + 1, 0);
	for (int i = 0; i <= n; i++)
		edj[i].clear();
}
int main()
{
	fast();
	string s;
	while (cin >> n&&n)
	{
		Scc(n);
		while (getline(cin, s), s != "0")
		{
			stringstream ss(s);
			int u, v;
			ss >> u;
			while (ss >> v)
			{
				edj[u].push_back(v);
				edj[v].push_back(u);
			}
		}
			for (int i = 1; i <= n; i++)
			{
				if (dfn[i] == -1)
					Tarjanbridge(i, -1);
			}
			scc = 0;
		for (int i = 1; i <= n;i++)
		if (instack[i] == 1)
			scc++;
		cout << scc << endl;
	}
	

}
