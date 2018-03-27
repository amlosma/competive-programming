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
int arr[1001], ar[1001], sum[1001][1001],n;
void prim()
{ 
	ar[2] = ar[3] = ar[5] = ar[7] = ar[11] = ar[13] = ar[17] = ar[19] = ar[23] = ar[29] = ar[31] = ar[37] = ar[41] = 1;
}
int pr[20] = { 1 };
 vector<bool>vis(20, 0);
 
 void check(int st,vector<bool>vis)
 {
	 prim();
	 if (st == n)
	 {
		 if (ar[pr[n-1]+1]==0) 
			 return;
		 printf("1");
		 for (int i = 1; i < n; ++i)
			 printf(" %d", pr[i]);
		 printf("\n");
		 return;
	 }
	 for (int i = 2; i <= n; ++i) {
		 if (vis[i]) continue;
		 if (ar[pr[st-1] + i]) {
			 vis[i] = 1;
			 pr[st] = i;
			 check(st + 1, vis);
			 vis[i] = 0;
		 }
	 }
 }
 int main()
 {

	 int  x = 0;
	 while (cin >> n&&n)
	 {
		 if (x++) puts("");
		 cout << "Case " << x << ":\n";

		 check(1, vis);
		 for (int i = 0; i < 20; i++)vis[i] = 0;
	 }
 }
