/*

    Harsh Vardhan :)

*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 2123456
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define mp make_pair
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INT_MAX 2147483647
#define pb push_back
#define itr(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> li;
typedef pair<int,pii> i3;

const int N = 1e5;
int t[MAX];
int n;  // array size
void build() // build the tree
{
	for(int i = n - 1; i > 0; i--)
	{
		t[i] = t[i << 1] + t[i << 1 | 1];
	}
}

void modify(int p,int val)  // set value at position p
{
	for(t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p^1];
}

int query(int l,int r)   // sum on interval [l, r)
{
	int res = 0;
	for(l += n,r += n; l < r; l >>= 1,r >>= 1)
	{
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}
int main()
{
    //freopen("H:\\input.txt","r",stdin);
    //freopen("H:\\output.txt","w",stdout);
    gi(n);
    for(int i = 0; i < n; i++)
    {
    	gi(t[n+i]);
    }
    build();
    cout << query(0,3) << endl;
    modify(0,1);
    cout << query(0,3);
    return 0;
}
