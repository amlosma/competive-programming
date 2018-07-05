//http://codeforces.com/contest/713/problem/A
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
#define endl "\n"
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int n, m;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < n;
}
/*
كُن مُشعًّا ، كُن شخصًا يُستضاءُ بهِ أملًا ، و اصنع مِن نفسك روحًا يُحبّها الله ??
*/
vector<bool >pr(5000, true);
void prime(){
	for (int i = 2; i < 5000; i++)
	{
		if (pr[i])
		for (int j = i * 2; j < 5000; j += i)
		{
			pr[j] = 0;
		}
	}
}
map<string, int>mp;
int main()
{
	fast();
	ll n, x;
	char c;
	cin >> n;
	string s,w="";
	while (n--)
	{
		cin >> c;
			w = "";
			cin >> s;
			for (int i = sz(s) - 1;i>=0; i--)
			{
				if ((s[i]-'0')%2)
					w += '1';
				else
					w += '0';
			
			}
			
			while (sz(w) < 18)w += '0';
			reverse(all(w));
			if (c == '-')
				mp[w]--;
			else if (c=='+') 
				mp[w]++;
			else
			cout << mp[w] << endl;
		
	}

}
