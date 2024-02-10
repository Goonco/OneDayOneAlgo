/*
    [BOJ2467_용액] - 23.02.06
    * 이분탐색을 이용한 문제
    * 양수값을 사용하여 lower_bound를 사용할 수 있도록 구현
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<ll> plus;
    vector<ll> minus;

    ll num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (num > 0)
            plus.push_back(num);
        else
            minus.push_back(-num);
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    ll minDif = 2000000000;
    pair<ll, ll> minPair;

    
    if (plus.size() < minus.size()) {
        for (ll p : plus) {
            auto it = lower_bound(minus.begin(), minus.end(), p);
            int idx = distance(minus.begin(), it);

            if (idx >= minus.size()) idx--;

            if (minDif > abs(minus[idx] - p)) {
                minDif = abs(minus[idx] - p);
                minPair = { -minus[idx], p };
            }
            if (idx - 1 >= 0 && minDif > abs(minus[idx - 1] - p)) {
                minDif = abs(minus[idx - 1] - p);
                minPair = { -minus[idx - 1], p };
            }
        }
    }
    else {
        for (ll p : minus) {
            auto it = lower_bound(plus.begin(), plus.end(), p);
            int idx = distance(plus.begin(), it);

            if (idx >= plus.size()) idx--;

            if (minDif > abs(plus[idx] - p)) {
                minDif = abs(plus[idx] - p);
                minPair = { -p, plus[idx] };
            }
            if (idx - 1 >= 0 && minDif > abs(plus[idx - 1] - p)) {
                minDif = abs(plus[idx - 1] - p);
                minPair = { -p, plus[idx - 1] };
            }
        }
    }
    
    if (plus.size() >= 2 && minDif > plus[0] + plus[1]) {
        minDif = plus[0] + plus[1];
        minPair = { plus[0], plus[1] };
    }

    if (minus.size() >= 2 && minDif > minus[0] + minus[1]) {
        minDif = minus[0] + minus[1];
        minPair = { -minus[1], -minus[0] };
    }

    cout << minPair.first << " " << minPair.second;

    return 0;
}