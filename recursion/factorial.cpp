// exmple of factorial using tail call recursion in C++17
#include <bits/stdc++.h>
using namespace std;

int fact_normal(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact_normal(n - 1);
}

int fact_tail(int n, int result) {
    if (n == 0) {
        return result;
    }
    return fact_tail(n - 1, n * result);
}

int main() {
    cout << "normal: " << fact_normal(5) << "\n";
    cout << "tail: " << fact_tail(5, 1) << "\n";
    return 0;
}