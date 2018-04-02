#include<iostream>
#include<fstream>
#include<istream>
#include<ostream>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<cmath>
#include <stdlib.h>
#include<iomanip>
#include<algorithm>
#include<assert.h>
using namespace std;
int m, n, cnt;
vector<vector<int> >vr;
bool vis[3002];
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
void fast()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int mx;
void dfs(int node,int dep)
{
	if (vis[node])
		return;
	mx = max(mx, dep);
	vis[node] = true;
	for (int i = 0; i < vr[node].size(); i++)
	{
		if (vis[vr[node][i]] == false)
			dfs(vr[node][i], dep + 1);
	}
}


int main()
{
	vector<int>vv;

	vr.resize(2001);
	int x;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x != -1)
			vr[x].push_back(i);
		else
			vv.push_back(i);
	}
	for (int i = 0; i <vv.size(); i++)
	{
		dfs(vv[i], 1);
	}
	if (mx == 1)cout << mx << endl;
	else
	cout << mx << endl;
	cin >> n;
}
