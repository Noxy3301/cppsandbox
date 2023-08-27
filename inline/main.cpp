#include <iostream>
#include <chrono>

// 非インライン関数
int add_normal(int a, int b) {
    return a + b;
}

// インライン関数
inline int add_inline(int a, int b) {
    return a + b;
}

int main() {
    const int iterations = 1000000000; // 10億回の呼び出し
    int sum = 0;

    // 非インライン関数の計測
    auto start_normal = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sum += add_normal(i, i);
    }
    auto end_normal = std::chrono::high_resolution_clock::now();
    auto duration_normal = std::chrono::duration_cast<std::chrono::microseconds>(end_normal - start_normal).count();

    // インライン関数の計測
    auto start_inline = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        sum += add_inline(i, i);
    }
    auto end_inline = std::chrono::high_resolution_clock::now();
    auto duration_inline = std::chrono::duration_cast<std::chrono::microseconds>(end_inline - start_inline).count();

    std::cout << "Normal function duration: " << duration_normal << " microseconds\n";
    std::cout << "Inline function duration: " << duration_inline << " microseconds\n";
    
    return 0;
}