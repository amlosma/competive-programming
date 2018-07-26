#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <stdlib.h>
#include<assert.h>
using namespace std;
#define PI 3.14159265359
#define OO 1e9
#define S second
#define F first
#define fr(a,b)    for (int i = a; i < b;i++)
#define rfr(a,b)    for (int i = b;i >= a;i--)
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
int n, m,cnt;
bool valid(int i, int j)
{
	return i >= 0 && i < n&&j >= 0 && j < m;
}
struct Edge {
	int x, y, v;
};
Edge D[100000], E[100000];
void sort(int n) {
	int w[1001] = {}, i;
	for (i = 0; i < n; i++)
		w[D[i].v]++;
	for (i = 999; i >= 0; i--)
		w[i] += w[i + 1];
	for (i = 0; i < n; i++) {
		E[--w[D[i].v]] = D[i];
	}
}
int p[10001], r[10001];
void init(int n) {
	int i;
	for (i = 0; i <= n; i++)
		p[i] = i, r[i] = 1;
}
int find(int x) {
	return p[x] == x ? x : (p[x] = find(p[x]));
}
int joint(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (r[x] > r[y])
			r[x] += r[y], p[y] = x;
		else
			r[y] += r[x], p[x] = y;
		return 1;
	}
	return 0;
}
int main() {
	int t, n, m, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		int sum = 0;
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &D[i].x, &D[i].y, &D[i].v);
			sum += D[i].v;
		}
		sort(m);
		init(n);
		for (i = 0; i < m; i++) {
			if (joint(E[i].x, E[i].y))
				sum -= E[i].v;
		}
		printf("%d\n", sum);
	}
	scanf("%d", &t);
	return 0;
}

	
