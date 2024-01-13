/*
    [BOJ2295_세_수의_합] - 23.01.13
    * 생각의 흐름이 필요했던 문제. N이 1000이므로 N^4은 시간 초과가 발생하니 N^2 두 개로 나누는 것은 어떨까?라는 발상에서 시작.
    * 역시 문제를 잘못읽어 틀리기도 했음. 선택되는 수가 모두 동일해도 상관없었음.
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    unordered_set<int> plus;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            plus.insert(numbers[i] + numbers[j]);
    }

    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j <= i; j++) {
            auto it = plus.find(numbers[i] - numbers[j]);

            if (it != plus.end()) {
                cout << numbers[i];
                return 0;
            }
        }
    }

    return 0;
}
