// https://www.acmicpc.net/problem/5543
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int burgerA, burgerB, burgerC;
    int coke, soda;
    int setPrice = 0;
    cin >> burgerA >> burgerB >> burgerC >> coke >> soda;

    if (burgerA < burgerB) {
        if (burgerA < burgerC) setPrice += burgerA;
        else setPrice += burgerC;
    }
    else {
        if (burgerB < burgerC) setPrice += burgerB;
        else setPrice += burgerC;
    }
    setPrice += (coke > soda) ? soda : coke;
    setPrice -= 50;

    cout << setPrice << '\n';
}