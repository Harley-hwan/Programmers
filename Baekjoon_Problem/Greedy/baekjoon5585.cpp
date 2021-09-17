#include <iostream>
#include <string>
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int change = 1000 - n;
    int count = 0;

    while(change) {
        if (change >= 500) {
            // cout << change << endl;
            change -= 500;
            count++;
        }
        else if (change >= 100){
            // cout << change << endl;
            change -= 100;
            count++;
        }
        else if (change >= 50) {
            change -= 50;
            count++;
        }
        else if (change >= 10){
            // cout << change << endl;
            change -= 10;
            count++;
        }
        else if (change >= 5){
            // cout << change << endl;
            change -= 5;
            count++;
        }
        else if (change >= 1){
            // cout << change << endl;
            change -= 1;
            count++;
        } 
    }
    // 999
    // 500  1
    // 100  4
    // 50   1
    // 10   4
    // 5    1
    // 1    4

    cout << count << endl;




    return 0;
}