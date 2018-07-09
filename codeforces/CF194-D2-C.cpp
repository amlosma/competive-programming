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
/*
كُن مُشعًّا ، كُن شخصًا يُستضاءُ بهِ أملًا ، و اصنع مِن نفسك روحًا يُحبّها الله ??
*/

char ch[1000][1000];
int vis[101][100];
int cnt = 0;
void dfs(int i, int j)
{
	if (ch[i][j] == '.')return;
	vis[i][j] = 1;
	for (int t = 0; t < 4; t++)
	{
		int a = i + dx[t];
		int b = j + dy[t];
		if (valid(a, b) && !vis[a][b])
			dfs(a, b);
	}
}
void check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ch[i][j] == '#'&&vis[i][j] == 0)
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
}
int main(){
	cin >> n >> m;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;  j++)
		{
			cin >> ch[i][j];
			if (ch[i][j] == '#')x++;
		}
	}
	if (x <= 2)return cout << -1, 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ch[i][j] == '#')
			{
				cnt = 0;
				for (int x = 0; x < n; x++)
				for (int y = 0; y<m; y++)
					vis[x][y] = 0;
				ch[i][j] = '.';
				check();
				if (cnt>1)
				return cout << 1, 0;
				ch[i][j] = '#';
			}
		}
	}
	cout << 2;
}
