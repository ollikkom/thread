#include <iostream>
#include <thread>
#include "InfInt.h"
#include <exception>

void Factorial(int num, InfInt &fact) {
    fact = 1;
    for (int i = 1; i <= num; ++i) {
        fact = fact*i;
    }
};

InfInt C(int n, int k) {
    if (k == 0 || n == 0) return 0;
    if (k < 0 || n < 0 || k > n) return 0;
    InfInt fact1, fact2, fact3;

    std::thread thread1(Factorial, n, &fact1);
    std::thread thread2(Factorial, k, &fact2);
    std::thread thread3(Factorial, (n - k), &fact3);

    thread1.join();
    thread2.join();
    thread3.join();
    return fact1 / (fact2 * fact3);
}

int main() {
    InfInt cnk, cnk1;
    cnk = C(2, 1);
    cnk1 = C(50, 3);
    std::cout << cnk << std::endl;
    std::cout << cnk1 << std::endl;
    return 0;
}