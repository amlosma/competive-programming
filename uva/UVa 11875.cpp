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
double pp(double x, double y)
{
	return sqrt(((x*x) - (y*y)));
}

int main()
{
	//cout << sqrt(4.0 * 4.0);
	fast();
	int x, y, d;
	cin >> n;
	int test = 0;
	while (n--)
	{
		int arr[30];
		set<int>st;
		cout << "Case " << ++test << ": ";
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			st.insert(x);
		}
		int i = 0;
		for (auto a : st)
		{
			arr[i] = a;
			i++;
		}
		cout << arr[i / 2] << endl;
	}
}
