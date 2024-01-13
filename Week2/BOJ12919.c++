/*
    [BOJ12919_A와_B_2] - 23.01.07
    * 최초에 deque를 이용할까라는 생각을 했지만 string과 pop_back, reverse 메소드를 사용하여 구현했다.
    * 보다 빠른 풀이를 위해선 단순 index를 이용하여 구현할 수 있을 것 같다.
    * 확실히 C++을 너무 못다루는 느낌이 든다. C++의 포인터 개념에 대한 공부가 필요할 것 같다.
    * 이를 테면 단순 string copy = target으로 문자열을 복사할 수 있다는 사실 등에 대해 전혀 모르고 있었다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string bef, aft;

int cutOutString(string target) {
    if (bef.size() == target.size()) 
        return !bef.compare(target) ? 1 : 0;
    
    int res = 0;
    if (target[target.size() - 1] == 'A') { 
        string copy = target;
        copy.pop_back();
        res = cutOutString(copy) ;
    }

    if (!res && target[0] == 'B') {
        string copy = target;
        reverse(copy.begin(), copy.end());
        copy.pop_back();
        res = cutOutString(copy);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> bef >> aft;

    cout << cutOutString(aft);
    return 0;
}
