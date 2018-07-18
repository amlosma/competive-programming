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
string mu(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	if (n1 == 0 || n2 == 0)
		return "0";
	vector<int> result(n1 + n2, 0);

	int i_n1 = 0;
	int i_n2 = 0;

	
	for (int i = n1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';
		i_n2 = 0;

		           
		for (int j = n2 - 1; j >= 0; j--)
		{
			
			int n2 = num2[j] - '0';

			int sum = n1*n2 + result[i_n1 + i_n2] + carry;

			carry = sum / 10;

			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}
		if (carry > 0)
			result[i_n1 + i_n2] += carry;
		i_n1++;
	}
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;
	if (i == -1)
		return "0";
	string s = "";
	while (i >= 0)
		s +=to_string(result[i--]);

	return s;
}
string dv(string s, ll x)
{
	string ans;

	int idx = 0;
	int temp = s[idx] - '0';
	while (temp < x)
		temp = temp * 10 + (s[++idx] - '0');
	while (s.size() > idx)
	{
		ans += (temp /x) + '0';

	
		temp = (temp % x) * 10 + s[++idx] - '0';
	}
	if (ans.length() == 0)
		return "0";
	return ans;

}
int main(){
	//cout << mu("20", "10");
	//cout << dv("20", 10);*/
	fast();
	int t;
	ll  n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;

		for (ll i = 0; i < m; i++)
		{
		cin>>arr[i];
		n -= arr[i];
		}
		if (n < m - 1) {
			cout << 0 << endl;
			continue;
		}
		n++;
		if (m >(n - m))
			m= n - m;

		string fact = "1";
		
		for (ll i = n,j=m; i > (n - m); i--,j--)
		{
			string b = to_string(i);
			fact = mu(fact, b);
		}
		for (ll i = m; i > 1; i--)
		{
			fact = dv(fact, i);
		}
		cout << fact << endl;
	}
}
