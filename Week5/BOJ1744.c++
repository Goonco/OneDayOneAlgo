/*
    [BOJ1744_수_묶기] - 23.02.03
    * 문제를 잘못읽었다.. 훨씬 쉬운 그리디 문제였다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> plus;
    vector<int> minus;

    int sum = 0, tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        sum += tmp;
        if (tmp > 0) plus.push_back(tmp);
        else minus.push_back(tmp);
    }

    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end());

    if (plus.size() > 1) {
        for (int i = plus.size() - 1; i > 0; i -= 2) {
            if (plus[i] + plus[i - 1] > plus[i] * plus[i - 1]) break;
            sum -= (plus[i] + plus[i - 1]);
            sum += plus[i] * plus[i - 1];
        }
    }

    if (minus.size() > 1) {
        for (int i = 0; i < minus.size() - 1; i += 2) {
            if (minus[i] + minus[i + 1] > minus[i] * minus[i + 1]) break;
            sum -= (minus[i] + minus[i + 1]);
            sum += minus[i] * minus[i + 1];
        }
    }

    cout << sum;

    return 0;
}