#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll num; 
	cin >> num;

	ll arr[num];
	for (ll i=0; i<num; i++)
		cin >> arr[i];

	ll steps = 0;

	sort(arr, arr+num);
	ll median = arr[num/2];

	for (ll i=0; i<num; i++)
		steps += abs(median - arr[i]);

	cout << steps << "\n";
}
