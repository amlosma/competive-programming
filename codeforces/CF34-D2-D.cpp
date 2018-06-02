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
vector<int>v[100000];
int arr[100009];
void dfs(int x,int y )
{
	arr[x] = y;
	for (int i = 0; i < sz(v[x]); i++)
	{
		if (arr[v[x][i]]==0)
		{
			dfs(v[x][i], x);
		}
	}
}
int main()
{
	fast();
	int n, r1, r2,x;
	cin >> n >> r1 >> r2;
//	r1--, r2--;
	for (int i = 1; i <= n; i++)
	{
		if (i == r1)continue;
		cin >> x;
		
		v[x].push_back(i);
		v[i].push_back(x);
	}
	dfs(r2, -1);
	for (int i = 1; i <= n; i++)
	{
		if (i == r2)continue;
		cout << arr[i] << " ";

	}
}
