/* سئمت من كونى مسامحه دائما سئمت
اريد ان اصبح فتاه مختلفه تماما 
انا قويه وقويه جدا 
قويه اكثر منكن جميعا */
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
int arr[100][100];
int ans, sum;

void maxscore(int r,int sum)
{
	if (r >= 8)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (vis[i] || vis2[r - i + 8] || vis1[r + i])
			continue;
		vis[i] = vis2[r - i + 8] = vis1[r + i] = true;
		maxscore(i + 1,sum+arr[r][i]);
		vis[i] = vis2[r - i + 8] = vis1[r + i] = false;
		sum -= arr[r][i];
	}

}
int main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{

		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++)
				cin >> arr[i][j];
		}
		maxscore(0,0);
		cout << setw(5) << setiosflags(ios::right) << ans << '\n';
		ans = -1;
	
		memset(vis, 0, sizeof vis);
		memset(vis1, 0, sizeof vis1);
		memset(vis2, 0, sizeof vis2);
	}
}
