#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

#include <stdlib.h>
#include<assert.h>
using namespace std;
#define PI 3.14159265359
#define  pi acos(-1)
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
	
	fast();
	
	double a, b, v, A,s;
	while (cin >> a >> b >> v >> A>>s )
	{
		if (a == 0 && b == 0 && v == 0 && A == 0&&s==0)
			break;
		double x = s*v/2;
		
		double y = x * cos(A / 180*pi);
		
		double w = x * sin(A / 180 * pi);
		cout << fixed << setprecision(0) << y / a << " ";
		cout << fixed << setprecision(0)<< w / b << endl;
	}
}
