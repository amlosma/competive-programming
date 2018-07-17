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
	int from, to; double weight;
	
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
	
	while (1){
		adj.clear();
		pair<int, int>p[100001];
		cnt++;
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &u, &v);
			p[i].first = u;
			p[i].second = v;
		
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				Edge t;
				t.from = i, t.to = j;
				t.weight = sqrt((double)((p[i].first - p[j].first)*(p[i].first - p[j].first) + (p[i].second - p[j].second) *(p[i].second - p[j].second)));
				adj.push_back(t);
			}
		}
			sort(all(adj),comp);

		
		double ans = 0;
		for (int i = 0; i < n; i++)per[i] = i;
		for (int i = 0; i < sz(adj); i++)
		{
		
			int fr = find(adj[i].from);
			int sec = find(adj[i].to);
			if (find(0) == find(1))break;
			//Stone #1 is Freddy’s stone, stone #2 is Fiona’s stone
			if (fr != sec)
			{
				per[fr] = per[sec];
				ans =adj[i].weight;
			}
		}
		cout << "Scenario #" << cnt << endl;
		cout << "Frog Distance = "  << fixed<<setprecision(3) << ans << endl << endl;

	}

	return 0;
}

