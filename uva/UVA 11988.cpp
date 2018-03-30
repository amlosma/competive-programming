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
int main()
{	
	fast();
	string s;

	while (cin >> s)
	{
		string ss = "", ss2 = "";
		bool t = false;
		for (int i = 0; i < sz(s); i++)
		{
			if (s[i] == '[' || s[i] == ']')
			{
				ss = ss2 + ss;
				ss2 = "";
				if (s[i] == '[')
				t = true;
				else 
				t = false;
			}
			else
			{
				if (s[i] == '[' || s[i] == ']')
					continue;
				else if (t == true)
					ss2 += s[i];
				else if (t == false)
					ss += s[i];

			}
		}
	
		cout << ss <<ss2<< "\n";
	}


}
