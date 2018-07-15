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

int main() {
	fast();
	int  n, v, m;
	cin >> n >> m>> v;
	if (m < (n - 1) || ((((n - 1)*(n - 2)))/2 ) + 1 < m)
		return cout << -1,0;
	
		if (v == 1)
		{
			cout << 1 << " " << 2<<endl;
			m--;
			for (int i = 1; i <= n&&m; i++)
			{
				for (int j = i + 1; j <= n&&m;j++)
				if (j != 2 && i != 2)
					cout << i << " " << j << endl,m--;
			}
		}
		else
		{
			cout << 1 << " " << v << endl;
			m--;
			for (int i = 2; i <= n&&m; i++)
			{
				for (int j = i + 1; j <= n&&m; j++)
				
					cout << i << " " << j << endl, m--;
			}
		}
	
}
