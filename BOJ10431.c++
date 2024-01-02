/*
    [BOJ10431_줄세우기] - 23.01.02
    * 문제가 주절 주절 적혀있지만 사실 알고보면 Insertion Sort에 관한 문제이다.
    * 테스트 케이스가 최대 1000개이지만, 정렬해야하는 배열의 길이가 20으로 고정되어 있기 때문에 O(N^2)의 시간복잡도 풀이로도 통과가 가능해 보인다.
    * C++의 lower_bound를 이용해 (binary search를 이용해), O(NlogN)의 시간복잡도를 갖도록 구현했다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TEST_CASE;
    cin >> TEST_CASE;

    while(TEST_CASE--) {
        int tc;
        cin >> tc;

        vector<int> sortedArr;
        int ans = 0, num;
        for (int i = 0; i < 20; i++) {
            cin >> num;

            auto lb = lower_bound(sortedArr.begin(), sortedArr.end(), num);
            int index = distance(sortedArr.begin(), lb);
            ans += sortedArr.size() - index;
            
            sortedArr.insert(lb, num);
        }
        
        cout << tc << " " << ans << "\n";
    }

    return 0;
}
