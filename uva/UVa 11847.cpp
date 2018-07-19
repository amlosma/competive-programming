#include<bits/stdc++.h>
#include <stdlib.h>
#include<assert.h>
using namespace std;
#define PI 3.14159265359
#define OO 1e9
#define S second
#define F first
#define MP                  make_pair
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
#define sz(v) ( (int) (v.size()) )
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int n, m, c = 0;
int cnt;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j<m;
}
long long  arr[1000];

int main(){
	
	fast();
	int t;
	ll  n, m;
	
	while (cin>>n&&n)
	{
		int i = 0, sum = 0;
		while (1)
		{
			sum *= 2;
			sum++;
			if (sum >= n)break;
			i++;

		}
				cout << i << endl;

	}
}
