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
	for (int i = 2; i <100000; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			prime.push_back(i);
			for (int j = i*2; j < 100000; j += i)
			{
				vis[j] = 1;
			}
		}
	}
}
int str(string s)
{
	int sum = 0;
	for (auto i : s)
		sum += i - '0';
	return sum;
}
int pri(ll x)
{
	int i = 0;
	int sum = 0;
	ll n = x,r = sqrt(x);;
	while (x > 1&&i<sz(prime))
	{
		if (x%prime[i] == 0 && prime[i] <= r)
		{
			
			x /= prime[i];
			ll w = prime[i];
			while (w)
			{
				sum += w % 10;
				w /= 10;
			}
		}
		else
			i++;

	}
	if (n == x)
		sum = 0;
	else
	if (x > 1)
	{
		while (x)
		{
			sum += x% 10;
			x /= 10;
		}
	}
	return sum;
}


int main()
{
	
	fast();
	ll x, y, d;
	prim();
	cin >> n;
	int test = 0;
	while (n--)
	{
		cin >> x;
		x++;
		string s = to_string(x);
		while (1)
		{
			if (str(s) == pri(x))
			{
				cout << x << endl;
			     break;
		     }
			x++;
			s = to_string(x);

		}
	}
}
