#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

string s;

bool check(char c)
{
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}
string solve() {
	int cap, small;
	cap = small = 0;
	string str;
	for (int i = 0; i < s.length(); ++i)
	{
		/* code */
		if (check(s[i])) {
			cap++;
		} else {
			small++;
		}
	}
	if (cap > small) {
		for (int i = 0; i < s.length(); i++) {
			if (check(s[i])) str += s[i];
			else {
				str += (s[i] - 'a' + 'A');
			}
		}
		return str;
	} else {
		for (int i = 0; i < s.length(); i++) {
			if (check(s[i]))  str += (s[i] - 'A' + 'a');
			else {
				str += s[i];
			}
		}
		return str;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	//cout << "Case #" << t  << ": ";
	cin >> s;
	cout << solve();

}