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
bool vis[100000];
void prim()
{
	for (int i = 2; i < 100000; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			prime.push_back(i);
			for (int j = i * 2; j < 100000; j += i)
			{
				vis[j] = 1;
			}
		}
	}
}
		int main()
{
	
	fast();
	ll x;
	
	while (cin>>x)
	{
		if (x == 0)break;
		
		if ((ll(sqrt(x))*(ll(sqrt(x)))) != x)
			cout << "no"<<endl;

		else
			cout << "yes"<<endl;

	}
}
