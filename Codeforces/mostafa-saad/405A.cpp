#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		/* code */ cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		/* code */cout << a[i] << " ";
	}
}