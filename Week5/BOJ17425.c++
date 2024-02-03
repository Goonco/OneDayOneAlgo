/*
    [BOJ17425_약수의_합] - 23.01.30
    * 아리토스테네스의 체 + prefix sum
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int LIMIT = 1000000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<ll> arr(LIMIT + 1, 1);
    for (int i = 2; i <= LIMIT; i++) arr[i] += i;
    for (int i = 2; i <= (int)sqrt(LIMIT); i++) {
        for (int j = i*i; j <= LIMIT; j += i) {
            arr[j] += i;

            if (j / i != i) arr[j] += j / i;
        }
    }

    vector<ll> pfxSum(LIMIT + 1, 0);
    pfxSum[1] = arr[1];
    for (int i = 2; i <= LIMIT; i++)
        pfxSum[i] = pfxSum[i - 1] + arr[i];

    int TEST_CASE;
    cin >> TEST_CASE;

    int tmp;
    while (TEST_CASE--) {
        cin >> tmp;
        cout << pfxSum[tmp] << "\n";
    }

    return 0;
}