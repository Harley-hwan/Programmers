#include <iostream>
#include <string>

using namespace std;
string thousand_seperator(int uValue) {
    string strValueTS;
    int j , i = 0, k = 0;

    int temp = uValue;

    int p = 1;

    while( temp > 0) //counting number of digits
    {
        temp /= 10;
        p *= 10;
        i++;
    }
    j = i % 3;
    p /= 10;
    while( i > 0 )//display integer number with 1000 seperator
    {
        strValueTS += char ((uValue/p) +'0');
        uValue %= p;
        p /= 10;
        i--;
        k++;
        j--;

        if ((k % 3 == 0 && i > 0)||(j == 0 && i > 2) )
        {
            strValueTS += ",";
            k = 0;
        }
    }
    return strValueTS;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const char* amountText = "10,000";
    string str(amountText);
    string str2;
    
    for(int i = 0; i <= sizeof(amountText); i++) {
        if(amountText[i] != ',') str2 += amountText[i];
    }
    str2 += '0';
    int str2_int= stoi(str2);
    cout << str2_int <<"\n";
    string str22 = thousand_seperator(str2_int);
    

    //if (str != str2) answer = false;

    cout <<str<<"\n";
    if (str22 == str)   cout << "true";
    else                cout << "false";
    //cout << str22 << "\n";
    return 0;
}