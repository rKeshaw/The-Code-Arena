#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll num, sum;
	cin >> num >> sum;

	unordered_map<ll, ll> seen;
		
	vector<ll> arr(num);
	for (int i=0; i<num; i++){
		cin >> arr[i];

	}
	
	seen.reserve(size_t(num*1.3));

	for (int i=0; i<num; i++){
		ll x = arr[i];
		ll need = sum - x;
		auto it = seen.find(need);
		if (it != seen.end()){
			cout << it->second + 1 << " " << i + 1 << "\n";
			return 0;
		}
		seen[x] = i;
	}
	
	cout << "IMPOSSIBLE" << "\n";
}
