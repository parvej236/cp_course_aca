#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, int a, int b) {
    if(n == 0) {
        return a;
    }
    return fibonacci(n - 1, b, a + b);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n, 0, 1) << endl;
    return 0;
}