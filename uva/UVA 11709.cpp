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
vector<int>edj[10001];
int dfn[10001], low[10001], instack[10001],comp[10000],vis[10001];
int ndfs;
vector<int> Stack;
int scc;
void Tarjan(int node)
{
	dfn[node] = low[node] = ++ndfs;
	Stack.push_back(node);
	instack[node] = 1;
	
	for (int i = 0; i < sz(edj[node]); i++) {
		int nxt = edj[node][i];
		if (dfn[nxt] == -1) {
			Tarjan(nxt);
			low[node] =
				min(low[node], low[nxt]);
		}
		else if (instack[nxt])
			low[node] =
			min(low[node], dfn[nxt]);
	}
	if (dfn[node] == low[node]) {
		++scc;
		int nxt;
		do {
			nxt = Stack.back();
			Stack.pop_back();
		
				instack[nxt] = 0;
		} while (node != nxt);
	}
}

map<string, int>mp;
void Scc(int n)
{

	fill(dfn, dfn + n + 1, -1);
	fill(low, low + n + 1, -1);
	fill(instack, instack + n + 1, 0);
	

	for (int i = 0; i <= n; i++)
		edj[i].clear();
	mp.clear();
}

int main()
{
	fast();
	string s,ss;
	while (cin >> n >> m && n != 0){

		Scc(n);
		cin.ignore();

		for (int i = 0; i < n; i++){
			getline(cin, s);
			mp[s] = i;
		}
		for (int i = 0; i < m; i++){
			getline(cin, s);
			getline(cin, ss);
			edj[mp[s]].push_back(mp[ss]);
		}
		for (int i = 0; i < n;i++)
		if (dfn[i] == -1)
			Tarjan(i);
		cout << scc << endl;
		scc = 0;
	}
}
