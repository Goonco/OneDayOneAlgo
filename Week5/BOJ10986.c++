/*
    [BOJ10986_나머지_합] - 23.01.31
    * Prefix_sum과 modular calculation. 항상 overflow를 조심하자 ㅠㅠ..
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<ll> prefix_mod(N, 0);
    // prefix_mod[i] = (a0 + ... + ai) % mod
    // (ai + ... aj)% mod = 0이 되려면 prefix_mod[j] - prefix_mod[i] = 0

    vector<ll> saveMod(M, 0);

    for (int i = 0; i < N; i++) {
        cin >> prefix_mod[i];
        prefix_mod[i] %= M;

        if (i)
            prefix_mod[i] = (prefix_mod[i] + prefix_mod[i - 1]) % M;

        saveMod[prefix_mod[i]]++;
    }

    ll count = saveMod[0];
    for (ll i : saveMod) {
        if (!i) continue;
        count += i * (i - 1) / 2;
    }

    cout << count;
    return 0;
}