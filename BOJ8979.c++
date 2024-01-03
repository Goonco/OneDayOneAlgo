/*
    [BOJ8979_올림픽] - 23.01.03
    * 구조체 배열에 대한 custom sorting이 필요하다.
    * 입력을 받고 단순히 한번의 검색만 필요하므로 정렬하지 않고 단순 O(N)으로 순회하는 것이 보다 효율적이다.
    * 여러 국가에 대한 등수를 확인해야 할 경우 정렬 및 binary search를 이용하는 것이 효율적이므로, custom sorting 및 lower_bound 함수를 활용하여 구현했다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Country {
    int num;
    int g;
    int s;
    int b;
};

using namespace std;

bool compareCountry(const Country& a, const Country& b) {
    if (a.g != b.g) return a.g > b.g;
    if (a.s != b.s) return a.s > b.s;
    return a.b > b.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int countryN, target;
    cin >> countryN >> target;

    vector<Country> place;
    Country targetCountry;
    int num, g, s, b;
    for (int i = 0; i < countryN; i++) {
        cin >> num >> g >> s >> b;
        place.push_back({ num, g, s, b });

        if (num == target) targetCountry = { num, g, s, b };
    }

    sort(place.begin(), place.end(), compareCountry);

    auto lb = lower_bound(place.begin(), place.end(), targetCountry, compareCountry);
    int index = distance(place.begin(), lb);
    
    cout << index + 1;

    return 0;
}
