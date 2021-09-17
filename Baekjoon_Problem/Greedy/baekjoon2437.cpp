#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2437번: 저울 (그리디 알고리즘, 정렬)

int n;
int arr[1001];

int main() {

    // 저울추 입력
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 저울추 정렬
    sort(arr, arr + n);

    int answer = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > answer) break;
        answer += arr[i];
        cout << "arr[i]: " << arr[i] << "\n";
        cout << "answer: " << answer << "\n";
    }
    cout << answer;
    return 0;
}

    /* 내가 가진 저울추로 1~K무게 모두 만들 수 있다 가정.
     * 다음 저울추 (1)가 K무게보다 같거나 작으면,
     * 다음 추로 (1 + L) ~ (K + L) 무게를 모두 만들 수 있다.
     * 그러므로, 총 1 ~ (K + L)무게를 모두 만들 수 있다가 된다. */

    // 1 1 2 3 6 7 30
    // 결과값 산출
    // 1, 2, 3, 4 무게를 만들수 있따.
    // 다음 저울추가 5면 -> 5, 6, 7, 8, 9 무게를 만들 수 있다.
    // 따라서 1 ~ 9 무게 모두 만들 수 있다.
    // 하지만 다음 추가 6이면 무게 5는 불가능.



// --------------------------------------------------
// 메모리 초과

// int wt[1001];
// int nums[1001];
// vector<int> psbNums;

// int n, w, sum;

// void comb(int num, int idx, int k) {
//     if (idx > k)
//     {
//         sum = 0;
//         for (int i = 1; i <= k; i++) sum += nums[i];
//         psbNums.push_back(sum);
//         return;
//     }

//     if (num > n) return;
    
//     nums[idx] = wt[num];

//     comb(num + 1, idx + 1, k);
//     comb(num + 1, idx, k);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     cin >> n;
    
//     for (int i = 1; i <= n; i++) { 
//         cin >> wt[i];
//     }
    
//     for(int i = 1; i <= n; i++) {
//         comb(1, 1, i);
//     }    
//     sort(psbNums.begin(), psbNums.end());
//     psbNums.erase(unique(psbNums.begin(), psbNums.end()), psbNums.end());

//     // for(int i = 0; i < psbNums.size(); i++) {
//     //     cout << psbNums[i] << " ";
//     // }
//     int cnt = 1;
//     for (int i = 0; i < psbNums.size(); i++) {
//         if (psbNums[i] != cnt) {
//             cout << cnt << "\n";
//             return 0;
//         }
//         cnt++;
//     }

//     return 0;
// }