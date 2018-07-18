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
int gcd(int f, int s) { return !s ? f : gcd(s, f % s); }
int lcm(int f, int s) { return (f/ gcd(f, s)) * s; }
int n, m;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}
vector<ll >prime;
bool vis[100000];
int arr[10001];
int main()
{
	
	fast();
	int x, y; string s;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		
		
		int i = 0,mx=0;
		
		getline(cin, s);
		istringstream is(s);
	

		while (is >> arr[i])
			++i;

		for (int j = 0; j < i; j++)
		{
			for (int k = j + 1; k < i; k++)
			{
				int w = gcd(arr[j], arr[k]);
				if (w>mx)
					mx=w;
			}
		}
		cout << mx << endl;
	}
}
