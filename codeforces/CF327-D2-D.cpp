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
كُن مُشعًّا ، كُن شخصًا يُستضاءُ بهِ أملًا ، و اصنع مِن نفسك روحًا يُحبّها الله ??
*/

char ch[1000][1000];
int vis[1001][1001];
vector<pair<pair<int, int>, char>>v;
void dfs(int i, int j)
{
	vis[i][j] = 1;
	v.push_back({{ i+1, j+1 }, 'B'});
	for (int t = 0; t < 4; t++)
	{
		int a = i + dx[t];
		int b = j + dy[t];
		if ((i < n&&i >= 0 && j < m&&j >= 0) && vis[a][b]==0&&ch[a][b]=='.')
		{
			
			dfs(a, b);
			v.push_back({ { a+1, b+1 }, 'D' });
			v.push_back({ { a+1, b +1}, 'R' });
		}
	}

}
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m;  j++)
		{
			cin >> ch[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ch[i][j] == '.'&&vis[i][j] == 0)
			{
				
				
				dfs(i, j);
		
			}
		}
	}
	cout << sz(v) << endl;
	//sort(all(v));
	for (auto i : v)cout << i.second << " " << i.first.first << " " << i.first.second << endl;

}
