#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using Clock = std::chrono::steady_clock;

template <typename F>
double measure_ns_per_op(F&& f, int iterations) {
    const auto start = Clock::now();
    for (int i = 0; i < iterations; ++i) {
        f();
    }
    const auto end = Clock::now();
    const auto total_ns =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return static_cast<double>(total_ns) / static_cast<double>(iterations);
}

std::string build_csv_naive(const std::vector<int>& data) {
    std::string out;
    for (const int v : data) {
        out += std::to_string(v);
        out += ",";
    }
    return out;
}

std::string build_csv_reserved(const std::vector<int>& data) {
    std::string out;
    out.reserve(data.size() * 6); // quick rough estimate
    for (const int v : data) {
        out += std::to_string(v);
        out.push_back(',');
    }
    return out;
}

std::size_t push_without_reserve(const std::vector<int>& data) {
    std::vector<int> v;
    for (int x : data) {
        v.push_back(x);
    }
    return v.size();
}

std::size_t push_with_reserve(const std::vector<int>& data) {
    std::vector<int> v;
    v.reserve(data.size());
    for (int x : data) {
        v.push_back(x);
    }
    return v.size();
}

int main() {
    std::cout << "Day1 Latency Lab\n";

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 99999);

    std::vector<int> data;
    data.reserve(10000);
    for (int i = 0; i < 10000; ++i) {
        data.push_back(dist(rng));
    }

    constexpr int iterations = 300;

    volatile std::size_t sink = 0;
    volatile std::size_t str_sink = 0;

    const double no_reserve_vec_ns = measure_ns_per_op([&]() {
        sink += push_without_reserve(data);
    }, iterations);

    const double reserve_vec_ns = measure_ns_per_op([&]() {
        sink += push_with_reserve(data);
    }, iterations);

    const double naive_str_ns = measure_ns_per_op([&]() {
        str_sink += build_csv_naive(data).size();
    }, iterations);

    const double reserved_str_ns = measure_ns_per_op([&]() {
        str_sink += build_csv_reserved(data).size();
    }, iterations);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n[Vector push_back]\n";
    std::cout << "without reserve: " << no_reserve_vec_ns << " ns/op\n";
    std::cout << "with reserve   : " << reserve_vec_ns << " ns/op\n";
    std::cout << "speedup        : " << no_reserve_vec_ns / reserve_vec_ns << "x\n";

    std::cout << "\n[String build CSV]\n";
    std::cout << "naive +=       : " << naive_str_ns << " ns/op\n";
    std::cout << "reserve + push : " << reserved_str_ns << " ns/op\n";
    std::cout << "speedup        : " << naive_str_ns / reserved_str_ns << "x\n";

    std::cout << "\n(ignore sinks) " << sink << " " << str_sink << "\n";
    return 0;
}

