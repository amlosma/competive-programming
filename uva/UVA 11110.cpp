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
int grid[100][100];
int vis[100][100];

void dfs(int x, int y)
{
	vis[x][y] = 1;

	int I, J;
	

	for (int i = 0; i<4; i++)
	{
		I = x + dx[i];
		J = y+ dy[i];

		if (valid(I, J)&&grid[x][y] == grid[I][J] && !vis[I][J])
			 dfs(I, J);

	}

	
}

int main(){

	bool ok;

	while (cin >> n&&n)
	{
		
		int cnt = 0;
		string s;
		cin.ignore();
		
		for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++)grid[i][j] = 0, vis[i][j] = 0;
		for (int i = 1; i<n; i++)
		{
			string s;
			getline(cin, s);
			stringstream is(s);
			int x, y;
			while (is >> x >> y)
			{
				grid[x - 1][y - 1] = i;
			}
		}
		ok = true;

		for (int i = 0; i<n ; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!vis[i][j])
				{
					dfs(i, j);
					
					cnt++;
				}
			}
		}

		if (cnt==n) cout << "good" << endl;
		else cout << "wrong" << endl;

	}

	return 0;
}
