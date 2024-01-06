/*
    [BOJ19637_IF문_좀_대신_써줘] - 23.01.06
    * 기본적으로 정렬된 값들을 제공하므로 lower_bound 함수의 사용이 가장 적합할 듯 하다.
    * 양수의 값만을 가지므로 unsigned type을 이용해 보았다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int labelNum, charNum;

    cin >> labelNum >> charNum;

    vector<string> labels;
    vector<unsigned> powers;

    string label;
    unsigned powPoint;
    for (int i = 0; i < labelNum; i++) {
        cin >> label >> powPoint;
        if (i && powPoint == powers[i - 1]) continue;

        labels.push_back(label);
        powers.push_back(powPoint);
    }

    unsigned target, idx;
    for (int i = 0; i < charNum; i++) {
        cin >> target;
        auto lb = lower_bound(powers.begin(), powers.end(), target);
        idx = distance(powers.begin(), lb);
        cout << labels[idx] << "\n";
    }

    return 0;
}
