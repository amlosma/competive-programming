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
	return i >= 0 && i < n&&j >= 0 && j < n;
}
/*
كُن مُشعًّا ، كُن شخصًا يُستضاءُ بهِ أملًا ، و اصنع مِن نفسك روحًا يُحبّها الله 💜
*/
vector<int>edj[10001];
int dfn[10001], low[10001],
instack[10001],  vis[10001],par[101];
int ndfs;
pair<int,int> Stk;
map<string, int>mp; map<int, string>mp2;
int scc;
bool root = false;
vector<string>st;
bool v[1001],fd[1001];


void cutpoint(int node, int root)
{
	low[node] = dfn[node] =ndfs++;
	vis[node] = true;
	int ch = 0;
	for (int i = 0; i<sz(edj[node]); i++)
	{
		int nxt = edj[node][i];
		if (!vis[nxt])
		{
			ch++;
			par[nxt] = node;
			cutpoint(nxt, root);
			low[node] = min(low[nxt], low[node]);

			if (node == root && ch>1) fd[node] = 1;
			else if (node != root && low[nxt] >= dfn[node]) fd[node] = 1;
		}
		else if (par[node] != nxt)
			low[node] = min(low[node], dfn[nxt]);
	}
	return;
}

void Scc(int n)
{
	for (int i = 0; i<n; i++) edj[i].clear();

	fill(vis, vis + n + 1, 0);
	fill(par, par + n + 1, 0);
	fill(fd, fd + n + 1, 0);

	mp.clear();
	st.clear();
	mp2.clear();
}
int main()
{
	fast();
	int  t = 1;
	string s, ss;
	while (cin >> n && n)
	{
		Scc(n);
		for (int i = 0; i<n; i++)
		{
			cin >> s;
			mp[s] = i;
			mp2[i] = s;
		}
		cin >> m;
		for (int i = 0; i<m; i++)
		{
			cin >> s >> ss;
			edj[mp[s]].push_back(mp[ss]);
			edj[mp[ss]].push_back(mp[s]);
		}
		for (int i = 0; i<n; i++)
		if (!vis[i]) cutpoint(i, i);
		for (int i = 0; i<n;i++)
		if (fd[i])
			st.push_back(mp2[i]);
		sort(st.begin(), st.end());
		if (t>1) cout << "\n";
		cout << "City map #" << t++ << ": ";
		cout << st.size() << " camera(s) found\n";
		for (int i = 0; i < sz(st); i++)
			cout << st[i] << endl;


		
	}

}


