#include<iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <queue>
#include <deque>
#define _USE_MATH_DEFINES // MUST NE BEFORE THE CMATH  FOR M_PI ,etc
#include <cmath>
#include <iomanip> // set precision
using namespace std;
#define FAST cin.tie(0);std::ios::sync_with_stdio(false);cout.tie(0);
#define endl "\n"
#define EACH(x , v) for(auto &x : v)
#define oo 1e9
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef long long int lli;
typedef vector<int> vin;
typedef vector<long long> vll;
typedef vector<double> vdouble;
typedef vector<vector<int>> GRAPH;
const double eps = 1e-9;
template<class T>
void read(T &x)
{
	cin>>x;
}
template<class T>
void read(vector<T>&v)
{
	EACH(x , v)
			read(x);
}
template<class ...someArgs , class T>
void read(T &a , someArgs& ...args)
{
	read(a) , read(args...);
}

const int MAX = 61;
ll dp[MAX][MAX];
string str;
ll palindrome(int idx1 , int idx2)
{
	if(idx1 == idx2)
		return 1; // single letter;
	if(idx1 + 1 == idx2)
		return 2 + (str[idx1] == str[idx2]); // 2 letters .. AB = 2 , AA = 3
	ll &ref = dp[idx1][idx2];
	if(ref != -1)
		return ref;
	ref = 0;
	if(str[idx1] == str[idx2])
		ref += 1 + palindrome(idx1 + 1, idx2 - 1);
	ref += palindrome(idx1 + 1, idx2);
	ref += palindrome(idx1, idx2 - 1);
	ref -= palindrome(idx1 + 1, idx2 - 1); // remove the duplicates
	return ref;
}
void solve()
{
	cin >> str;
	memset(dp, -1, sizeof(dp));
	cout << palindrome(0, (int)str.size() - 1);
}
int main(){
	FAST
	int tc;
	cin >> tc;
	while(tc--)
	{
		solve();
		cout << '\n';
	}
	return 0;
}

