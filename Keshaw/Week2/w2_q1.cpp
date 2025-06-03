#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> songs(n);
    for (ll i = 0; i < n; i++) {
        cin >> songs[i];
    }

    vector<ll> vals = songs;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int M = (int)vals.size();

    vector<int> comp(n);
    for (long long i = 0; i < n; i++) {
        comp[i] = int(lower_bound(vals.begin(), vals.end(), songs[i]) - vals.begin());
    }

    vector<int> lastPos(M, -1);

    long long maxLen = 0;
    long long start = 0;

    for (long long i = 0; i < n; i++) {
        int x = comp[i];
        if (lastPos[x] >= start) {
            start = lastPos[x] + 1;
        }
        lastPos[x] = (int)i;                   
        maxLen = max(maxLen, i - start + 1LL); 
    }

    cout << maxLen << "\n";
    return 0;
}

