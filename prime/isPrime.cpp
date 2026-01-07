#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int isPrime = 1;

    if (n <= 1) {
        cout << "Not Prime" << endl;
        return 0;
    }

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if(isPrime)
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;
}