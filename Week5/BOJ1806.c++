/*
    [BOJ1806_부분합] - 23.01.28
    * sliding window. 언급 내용 없음
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll N, S;
    cin >> N >> S;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    queue<ll> window;
    ll sum = 0, len = 0, minLen = 0;

    int iter = 0;
    for (iter; iter < N && sum < S; iter++) {
        sum += arr[iter];
        len++;
        window.push(arr[iter]);
    }

    minLen = len;
    for (iter; ; iter++) {
        while (!window.empty()) {
            if (sum - window.front() < S) break;

            sum -= window.front();
            len--;
            window.pop();
        }
        minLen = min(minLen, len);
        if (iter >= N) break;

        sum += arr[iter];
        window.push(arr[iter]);
        len++;
        
    }

    if (sum < S) cout << "0";
    else cout << minLen;

    return 0;
}