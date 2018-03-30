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
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

}
int xx, yy, n, m, i1, i2, d1, d2;
bool valid(int i, int j)
{
	return i >= 0 && i < n&& j >= 0 && j<m;
}
bool vis1[100], vis2[100], vis[100];
int dp[104][104];
int x[100],y[100];
int ans, sum;
bool f=false;
void check(int r,int r2)
{
	if (r == n)
	{
		if (r2 == d1)
			{f = true;return;}
		f = false;
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (vis[i])
			continue;
		if (r2 == x[i] || r2 == y[i])
		{
			vis[i] = true;
			if (r2 == x[i])
			{
				 check(r + 1, y[i]);
			   if (f)
				return;
		    }
			else
			{
				 check(r + 1, x[i]);
				if (f)
					return ;
			}
			vis[i] = false;
			
		}
	}
	return;
}
int main()
{	
		while (cin>>n>>m&&n)
		{
			bool ok =true, ok2 = true;
			scanf("%d%d%d%d", &i1, &i2, &d1, &d2);
			for (int i = 0; i < m; i++)
			{
				scanf("%d %d", &x[i], &y[i]);
				if (i2 == x[i] || i2 == y[i])ok = false;
				if (d1 == x[i] || d1 == y[i])ok2 = false;
			}
			if (ok || ok2)puts("NO");
			else
			{
				memset(vis, 0, sizeof vis);

				(check(0, i2));
				if (f)
					puts("YES");
				else
					puts("NO");
                                 f=false;
			
			}
	   }
}
