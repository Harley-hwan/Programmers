#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    vector<char> vec_str(s.begin(), s.end());

    int zero = 0;
    int one = 0;
    int answer = 0;

    for (int i = 0; i < vec_str.size()-1; i++) {
        if (vec_str[i] == '0' && vec_str[i] != vec_str[i+1]) zero++;
        else if (vec_str[i] == '1' && vec_str[i] != vec_str[i+1]) one++;
        else continue;
    }
//    cout << zero << " " << one << "\n";
    if (zero < one) cout << zero <<"\n";
    else            cout << one << "\n";

    return 0;
}


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     string s; cin >> s;

//     vector<char> vec_str(s.begin(), s.end());
//     int answer = 0;

    
//     for (int i = 0; i < vec_str.size()-1; i++) {
//         if (vec_str[i] != vec_str[i+1]) answer++;
//         else continue;
//     }
//     cout << answer;

//     return 0;
// }