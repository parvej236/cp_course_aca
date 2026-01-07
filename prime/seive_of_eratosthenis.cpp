#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n, bool prime[]) {
    memset(prime, true, sizeof(bool) * (n + 1));

    for(int p = 2; p * p <= n; p++) {
        if(prime[p] == true) {
            for(int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    bool prime[n + 1];

    sieveOfEratosthenes(n, prime);

    cout << "Prime numbers up to " << n << " are: ";
    for(int p = 2; p <= n; p++) {
        if(prime[p])
            cout << p << " ";
    }
    cout << endl;
    return 0;

    // recicrocal sum of prime numberss up to n
    // formaulae is 1/2 + 1/3 + 1/5 + 1/7 + .... + 1/p
    // sum in math is log(log(n)) + M where M is meissel-mertens constant approximately equal to 0.2614972128
    // the ultimate complexity of this algorithm is O(n log(log(n)))
}