/*لا تقهر عبدا حتى لا يؤذيك عاءه*/
/*((وَمَنْ أَعْرَضَ عَنْ ذِكْرِي فَإِنَّ لَهُ مَعِيشَةً ضَنكًا وَنَحْشُرُهُ يَوْمَ الْقِيَامَةِ أَعْمَى */
/**/
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
vector<long long >v;
void dfs(long long  m){
	if (m > 1e9)return;
	v.push_back(m);
	dfs(m * 10 + 4);
	dfs(m * 10 + 7);
}
int arr[100], x; bool vis[100];
void check(int i, int tp, int ind)
{
	if (x)return;
	if (i == 5)
	{
		x |= (tp == 23);
		
			return ;
	}
	for (int j = 0; j < 5; ++j)
	{
		if (vis[j])continue;
		vis[j] = 1;
		if (ind)
		{
			check(i + 1, tp + arr[j], 1);
			check(i + 1, tp - arr[j], 1);
			check(i + 1, tp * arr[j], 1);
		}
		else
		{
			check(i + 1, arr[j], 1);
		}
		vis[j] = 0;
	}
}
int main()
{

	while (1)
	{
		x = 0;

		for (int i = 0; i < 5;i++)
			scanf("%d", &arr[i]);
		if ((arr[0] +arr[1] +arr[3] +arr[2] + arr[4])==0)return 0;
		check(0, 0, 0);
		if (x == 0)
		puts("Impossible");

		else
		puts("Possible");

	}
}
