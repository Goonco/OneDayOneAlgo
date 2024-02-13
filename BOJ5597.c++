/*
    [BOJ5597_과제_안_내신_분..?] - 23.02.13
    * 크루즈 집중하기 + 재원이 장례식 이슈 (어제도 안함..)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<bool> arr(31, false);

    int n;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        arr[n] = true;
    }

    for (int i = 1; i <= 30; i++) {
        if (!arr[i]) cout << i << "\n";
    }

    return 0;
}