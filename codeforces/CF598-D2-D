/*لا تقهر عبدا حتى لا يؤذيك عاءه*/
#include<bits/stdc++.h>
#include <stdlib.h>
#include<assert.h>
using namespace std;
#define PI 3.14159265359
#define OO 1e9
#define S second
#define F first
#define MP                  make_pair
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
#define sz(v) ( (int) (v.size()) )
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int n, m, c = 0;
int cnt, tp;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}
char ch[1001][1001];
int vis[1001][1001];
int dfs(int x,int y,int cont)
{
	vis[x][y] = cont;
	for (int i = 0; i < 4; i++)
	if (valid(x + dx[i], y + dy[i]))
	{
		if (ch[x + dx[i]][y + dy[i]] == '.' && vis[x + dx[i]][y + dy[i]]==0)
		{
			dfs(x + dx[i], y + dy[i],cont);
		}
		else if (ch[x + dx[i]][y + dy[i]] == '*')
		{
			cnt++;
		}
	}
	return cnt;
}
int arr[10000001];
int main()
{
	int x,y, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ch[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cnt = 0;
			c++;
			if (ch[i][j] == '.'&&vis[i][j]==0)
			{ dfs(i, j, c);
			arr[c] = cnt;
			}
		}
	}
	while (q--)
	{
		cin >> x >> y;
		x--, y--;
		int w = vis[x][y];
		cout << arr[w] << endl;
		
		
	}
}
