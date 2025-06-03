#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num, sum;
	cin >> num >> sum;
	
	vector<pair<ll, ll>> arr(num);
	for (int i=0; i<num; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end(), [](auto &a, auto &b){
		return a.first < b.first;
	});

	for (int i=0; i<num-2; i++){
		ll tsum = sum - arr[i].first;
		ll left = i+1;
		ll right = num-1;
		
		while (left < right){
			ll ttsum = arr[left].first + arr[right].first;
			if (ttsum == tsum){
				int id1 = arr[i].second + 1;
				int id2 = arr[left].second + 1;
				int id3 = arr[right].second + 1;
				vector<int> out = {id1, id2, id3};
				sort(out.begin(), out.end());
				cout << out[0] << " " << out[1] << " " << out[2] << "\n";
				return 0;
			}
			else if (ttsum < tsum) left++;
			else right--;
		}
	}

	cout << "IMPOSSIBLE\n";
}
