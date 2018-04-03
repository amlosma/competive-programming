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
int main() {
	fast();
	int n, m,x,u;
	while (cin >> n >> m&&m&&n)
	{
		vector<int>v[1000009];
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v[x].push_back(i);
		}
		while (m--)
		{
			cin >> u >> x;
			if (u - 1 < sz(v[x]))
				cout << v[x][u - 1] + 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
	
}
