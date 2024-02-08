/*
    [BOJ10872_팩토리얼] - 23.02.08
    * 시간 없어서 후딱 함 ㅠㅠ..
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    ll fact = 1;
    for (int i = N; i >= 2; i--)
        fact *= i;
    cout << fact;

    return 0;
}