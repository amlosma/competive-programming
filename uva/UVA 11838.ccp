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

vector<int> edj[1005];
int dfn[1005], low[1005],instack[1005];

int ndfs;
vector<int> Stack;
int scc_cnt;

void Tarjan(int cur)
{
	dfn[cur] = low[cur] = ++ndfs;
	Stack.push_back(cur);
	for (int nxt : edj[cur]) {
		if (!dfn[nxt]) {
			Tarjan(nxt);
			low[cur] = min(low[cur], low[nxt]);
		}
		else if (find(Stack.begin(), Stack.end(), nxt) != Stack.end())  // if in Stack
			low[cur] = min(low[cur], dfn[nxt]);
	}
	if (dfn[cur] == low[cur]) {
		++scc_cnt;
		int nxt;
		do {
			nxt = Stack.back();
			Stack.pop_back();
		} while (cur != nxt);
	}
}

int main()
{
	fast();
	while (cin>>n>>m && (n || m)) {
		
		for (int i = 0; i <= n; i++)edj[i].clear();
		fill(dfn, dfn + n + 1, 0);
		fill(low, low + n+ 1, 0);
		ndfs = 0;
		Stack.clear();
		int u, v, p;
		for (int i = 0; i < m; ++i) {
			cin >> u >> v >> p;
			if (p == 1)edj[u].push_back(v);
			else{
				edj[v].push_back(u);
				edj[u].push_back(v);
			}
		}
		scc_cnt = 0;
		for (int i = 1; i <= n; ++i)
		if (!dfn[i] && scc_cnt <= 1) Tarjan(i);

		if (scc_cnt == 1) cout << 1 << endl;
		else cout<<"0"<<endl;
	}
}
