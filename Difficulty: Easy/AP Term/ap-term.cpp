#include <iostream>
using namespace std;

int main() {
    int a, d, n;
    cin >> a >> d >> n;

    int ans = a + (n - 1) * d;
    cout << ans;

    return 0;
}