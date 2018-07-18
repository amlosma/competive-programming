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
vector<ll >prime;
bool vis[20000000];
void prim()
{
	for (int i = 2; i <20000000; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			prime.push_back(i);
			for (int j = i * 2; j < 20000000; j += i)
			{
				vis[j] = 1;
			}
		}
	}
}
vector<pair<int, int>>pr;
void make()
{
	prim();
	for (int i = 1; i < sz(prime); i++)
	{
		if (prime[i - 1] + 2 == prime[i])
			pr.push_back({ prime[i - 1], prime[i] });
	}
}
int arr[10001];
int main()
{
	
	fast();
	int x;
	make();
	while (cin>>x)
	{
		cout << '('<<pr[x - 1].first << ", " << pr[x - 1].second<<')' << endl;
	}
}
