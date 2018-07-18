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
int main(){
	//cout << mu("20", "10");
	//cout << dv("20", 10);*/
	fast();
	int t;
	ll  n, m;
	
	while (cin>>n&&n)
	{
		string fact = "1";
		for (ll i = 1; i <= n; i++)
		{
			string b = to_string(i);
			fact = mu(fact, b);
		}
		cout << n << "! --" << endl;
		cout << setw(5) << "(" << 0 << ")" << setw(5) << count(all(fact), '0');
		cout << setw(5) << "(" << 1 << ")" << setw(5) << count(all(fact), '1');
		cout << setw(5) << "(" << 2 << ")" << setw(5) << count(all(fact), '2');
		cout << setw(5) << "(" << 3 << ")" << setw(5) << count(all(fact), '3');
		cout << setw(5) << "(" << 4 << ")" << setw(5) << count(all(fact), '4') << endl;
		cout << setw(5) << "(" << 5 << ")" << setw(5) << count(all(fact), '5');
		cout << setw(5) << "(" << 6 << ")" << setw(5) << count(all(fact), '6');
		cout << setw(5) << "(" << 7 << ")" << setw(5) << count(all(fact), '7');
		cout << setw(5) << "(" << 8 << ")" << setw(5) << count(all(fact), '8');
		cout << setw(5) << "(" << 9 << ")" << setw(5) << count(all(fact), '9') << endl;

	}
}
