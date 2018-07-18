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

int main()
{
	
	//fast();
	int x;
	
	while (cin>>x&&x>0)
	{
		bool r = 0; int ans = 0;
		for (int i = 100; i >= 2; i--)
		{
			n = x, m = 0;
			for (int j = i; j >= 1; j--)
			{
				if (n%i == 1)
				{
					n -= (n/i);
					n--;
					m++;
				}
			}
			if (m == i&&n%i == 0)
			{
				r = 1;
				ans = i;
				break;
			}
		}
		if (r == 1)
			printf("%d coconuts, %d people and 1 monkey\n", x, ans);
		else

			printf("%d coconuts, no solution\n", x);

	}
}
