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
pair<int, int>vis[10000][10000];
int cnt = 0;
bool dfs(int i, int j)
{
	int w = (i%n + n) % n;
	int y = (j%m + m) % m;
	if (ch[w][y] == '#')return 0;
	if (vis[w][y] != pair<int, int>{ 10000000, 10000000 })
	{
		if (vis[w][y] != pair<int, int>{i, j})
			return 1;
	}
	vis[w][y] = { i, j };
	for (int t = 0; t < 4; t++)
	{
		int a = i + dx[t];
		int b = j + dy[t];

		if (dfs(a, b))
			return true;

	}
	return false;
}
int main(){
	cin >> n >> m;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ch[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		vis[i][j] = { 10000000, 10000000 };
	for (int i = 0; i < n; i++)

	for (int j = 0; j < m; j++)
	{
		if (ch[i][j] == 'S') {
			if (dfs(i, j))cout << "Yes";
			else
				cout << "No";
			return 0;
		}

	}

}
