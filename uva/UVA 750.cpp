/*AML*/
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
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

}
int n, m, cnt;
bool valid(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j<m;
}
bool vis1[100], vis2[100], vis[100];
int dp[104][104];
int arr[100];
int ans, sum;
int x, y;
void check(int r)
{
	if (r == 8)
	{
		++ans;
	
		printf("%2d      ",ans);
		for (int i = 0; i < 7;i++)
			printf("%d ", arr[i] + 1);
		printf("%d\n", arr[7]+1);
		
			return;
	}
	if (r == y) check(r+ 1);
	else
	for (int i = 0; i < 8; i++)
	{
		{
			if (vis[i] || vis2[r - i + 8] || vis1[r + i])
			continue;
			vis[i] = vis2[r - i + 8] = vis1[r + i] = true;
			arr[r] = i;
			check(r + 1);
			vis[i] = vis2[r - i + 8] = vis1[r + i] = false;
		}
	}

}

int main()
{
	
	int t;bool c = false;
	cin >> t;
	while (t--)
	{
		cin >>x>>y ;
		x--, y--;
		memset(vis, 0, sizeof vis);
		memset(vis1, 0, sizeof vis1);
		memset(vis2, 0, sizeof vis2);
		vis[x] = vis2[y - x + 8] = vis1[x + y] = true;
		arr[y] = x;
		if (c)puts("");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		ans = 0;
		check(0);
		c = true;
	}
}
