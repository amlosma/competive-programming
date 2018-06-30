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
vector<int>edj[10001]; vector<vector<int>> comps;
int dfn[10001], low[10001], instack[10001], comp[10000], vis[10001];
map<string, int>mp;

set<string>r;

int ndfn;
vector<int> stk, Stack1;;
int p;
void tarjan(int node) {
	low[node] = dfn[node] = ndfn++, instack[node] = 1;
	stk.push_back(node);

	for (int i = 0; i < sz(edj[node]); i++) {
		int ch = edj[node][i];
		if (dfn[ch] == -1) {
			tarjan(ch);
			low[node] = min(low[node], low[ch]);
		}
		else if (instack[ch])
			low[node] = min(low[node], dfn[ch]);
	}

	if (low[node] == dfn[node]) {
		vector<int> temp;
		int x = -1;
		while (x != node)
		{
			x = stk.back();
			temp.push_back(x);
			instack[x] = 0;
			comp[x] = comps.size();
			stk.pop_back();

			
		}
		if (temp.size() > 1)comps.push_back(temp);

	}
}
void Scc()
{

	fill(dfn, dfn + 100 + 1, -1);
	fill(low, low + 100 + 1, -1);
	fill(instack, instack + 100+ 1, 0);

	comps.clear(); ndfn = 0;
	
}
vector<string>ans;
string word[1000];
void dfs(int u)
{
	ans.push_back(word[u]);
	vis[u] = 1;
	for (auto&v : edj[u])
	if (!vis[v])
		dfs(v);
}
int main() {
	fast();

	int n;
	while (cin >> n && n)
	{
		for (auto &v : edj)
			v.clear();
		map<string, int>mp;
		string s,a,b;
		cin.ignore();
		p = 1;
		for (int i = 0; i < n; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> a;
			if (mp[a] == 0)
				mp[a] = p;
			word[p] = a;
			p++;
			while (ss >> b) {
				word[p] = b;
				if (mp[b] == 0)
				{
					edj[mp[a]].push_back(p);
					mp[b] = p;
					p++;
				}
				else
					edj[mp[a]].push_back(mp[b]);

			}
		}
		Scc();
		for (int i = 1; i <= p; i++)
		if (dfn[i] == -1) tarjan(i);
		ans.clear();
		memset(vis, 0, sizeof vis);
		for (int i = 0; i<sz(comps);i++)
			dfs(comps[i][0]);
		sort(ans.begin(),ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size() - 1; i++)
			cout << ans[i] << " "; 
		cout << ans[ans.size() - 1] << endl;
	}
	
	
}
