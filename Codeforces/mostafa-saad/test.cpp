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


bool distance(int a, int b, int c, int d, int r) {
	if ((a - c) * (a - c) + (b - d) * (b - d) <= r * r)
		return true;
	else
		return false;
}


void solve() {
	int Xa, Ya, Xb, Yb;
	cin >> Xa >> Ya >> Xb >> Yb;
	int X1, Y1, X2, Y2;
	if (Xa < Xb) {X1 = Xa; X2 = Xb;} else {X1 = Xb; X2 = Xa;}
	if (Ya < Yb) {Y1 = Ya; Y2 = Yb;} else {Y1 = Yb; Y2 = Ya;}
	// cout << X2 << " " << Y2 << " " << X1 << " " << Y1;
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		int x, y, z;
		cin >> x >> y >> z;
		temp.push_back(x); temp.push_back(y); temp.push_back(z);
		v.push_back(temp);
	}
	// cout << v.size();
	vector<pair<int, int> > generals;
	for (int i = Y2; i >= Y1; i--) {

		for (int j = X2; j <= X1; j++) {
			// cout << j << " " << i << endl;
			if (i == Y2 || i == Y1) {pair<int, int> temp; temp = make_pair(j, i); generals.push_back(temp);}
			else {
				if (j == X2 || j == X1) {pair<int, int> temp; temp = make_pair(j, i); temp = make_pair(j, i); generals.push_back(temp);}
			}
			// cout << temp.first << " " << temp.second << endl;
			// cout << "(" << temp.first << "," << temp.second << ")" << " X:" << j << " Y:" << i << endl;

		}
	}
	cout << generals.size() << endl;
	/*
	for (auto it : generals) {
		cout << "(" << it.first << "," << it.second << ")" << endl;
	}
	*/

	vector<vector<int>>::iterator it;
	vector<pair<int, int>>::iterator iter;
	vector<pair<int, int>>::iterator eraser;
	for (it = v.begin(); it != v.end(); it++) {
		vector<int> temp = *it;
		int x = temp[0], y = temp[1], r = temp[2];
		iter = generals.begin();
		while (iter != generals.end()) {
			pair<int, int>gen = *iter;
			cout << gen.first << " " << gen.second << endl;
			if (distance(gen.first, gen.second, x, y, r)) {
				generals.erase(iter);
				iter = generals.begin();
			} else {
				iter++;
			}
		}

	}
	cout << generals.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int tc; cin >> tc;
	// for (int t = 1; t <= tc; t++) {
	//cout << "Case #" << t  << ": ";
	solve();
	// }
}