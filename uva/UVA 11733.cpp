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
struct Edge {
	int from,to, weight;
	
};
vector<Edge>adj,as;
int low[100001], per[100001],ndfs;
/*bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
};*/
bool comp(Edge e1, Edge e2){
	return e1.weight < e2.weight;
};
int find(int u) {
	if (per[u] == u)
		return u;
	return per[u] = find(per[u]);
}

int main() {
	int a,t,u,v,c,cnt=0;
	cin>>t;
	while (t--){
		adj.clear();
		cnt++;
		scanf("%d %d%d", &n, &m, &a);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d%d", &u, &v, &c);
			Edge x;
			x.from = u;
			x.to = v;
			x.weight = c;
			
			adj.push_back(x);
		
		}
			sort(all(adj),comp);
		int w = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++)per[i] = i;
		for (int i = 0; i < m; i++)
		{
		
			if (adj[i].weight >= a)break;
			int fr = find(adj[i].from);
			int sec = find(adj[i].to);
			if (fr != sec)
			{
				per[fr] = per[sec];
				ans += adj[i].weight;
				w++;
				if (w ==(n- 1))break;
			}
		}
		printf("Case #%d: %d %d\n", cnt, (ans+a*(n-w)) ,(n-w));

	}

	return 0;
}

