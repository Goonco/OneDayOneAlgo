/*
    [BOJ2437_저울] - 23.02.02
    * 누적합 문제. 머리만 잘 굴렸으면 굉장히 쉬웠다. 솔직히 골드2 수준은 아닌 것 같은데...
    * 하지만 결국 못풀었다, 시간복잡도가 터무니 없다면 Greedy를 항상 고려하자.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int NUM;
    cin >> NUM;

    vector<int> numbers;

    int num;
    for (int i = 0; i < NUM; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());

    bool flag = false;
    ll sum = 0;
    for (int i : numbers) {
        if (i > sum + 1) {
            break;
        }
        else sum += i;
    }

    cout << sum + 1;

    return 0;
}