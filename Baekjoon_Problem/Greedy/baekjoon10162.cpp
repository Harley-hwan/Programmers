#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    
    if (t % 10 != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << (t / 300) << " ";
    t %= 300;
    cout << (t / 60) << " ";
    t %= 60;
    cout << (t / 10);


    return 0;
}