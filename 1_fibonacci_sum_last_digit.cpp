 #include <iostream>

int fibonacci_sum_fast(long long n) {
    int equivalent = (n % 60);
    if (equivalent <= 1)
        return equivalent;
    int p1 = 0;
    int p2 = 1;
    int temp = 0;
    int sum = 1;
    for (int i = 2; i <= equivalent; i++) {
        // Save old value of p1
        temp = p1;
        // Advance p1
        p1 = p2;
        // Calculate new p2
        p2 = (temp + p1) % 10;
        // New last digit
        sum = ((sum + p2) % 10);
    }
    return sum;
}

int main() {
    long long n;
    std::cin >> n;
    int result = fibonacci_sum_fast(n);
    std::cout << result << std::endl;
    return 0;
}
