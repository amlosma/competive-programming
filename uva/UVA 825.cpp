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
int dx[] = { 0, 1, -1, 1, 1, 1, -1, -1 };
int dy[] = { 1, 0, 0, 1, -1, 1, -1 };
char grid[100][100];
bool vis[100][100];
int dp[104][104];

int floodfill(int i, int j)
{

	if (i == n - 1 && j == m - 1)
		return 1;
	int &ret = dp[i][j];

	if (ret != -1)return ret;
	ret = 0;
	for (int f = 0; f < 2; f++)
	{
		int nx = dx[f] + i;
		int ny = dy[f] + j;
		if (!(!valid(i, j) || grid[i][j] == 'x'))
			ret += floodfill(nx, ny);
	}
	return ret;

}
vector <string>val;
template<class T> void tovector(T par)
{
	stringstream ss(par);
	string t;
	while (ss >> t)
		val.push_back(t);
}
template <class T, class TT> TT toNewdatatype(T par)

{
	int x;
	stringstream ss(par);
	ss >> x;
	return x;
}
int main()
{
	int t;
	cin >> t;
	int w = 0;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				grid[i][j] = '.';
		}
		string s;
		cin.ignore();
		while (getline(cin, s) && s != "")
		{
			tovector<string >(s);
			int y = toNewdatatype<string, int>(val[0]);
			for (int i = 1; i < sz(val); i++)
			{
				int x = toNewdatatype<string, int>(val[i]);
				grid[y - 1][x - 1] = 'x';
			}
			val.clear();
		}
		/*for (int i = 0; i < n; i++)
		{
		for (int j = 0; j < m; j++)
		cout<<grid[i][j];
		cout << endl;
		}*/
		memset(vis, 0, sizeof vis);
		memset(dp, -1, sizeof dp);
		if (w == 1)cout << '\n';
		cout << floodfill(0, 0) << '\n';
		w = 1;
	}
}
