#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

// Problem 1 (Two Pointers):
// Sorted array nums and target are given.
// Return 0-based indices (i, j) such that nums[i] + nums[j] == target.
// If not found, return (-1, -1).
std::pair<int, int> two_sum_sorted(const std::vector<int>& nums, int target) {
    // TODO(day1): implement with two pointers.
    // Hint: left = 0, right = nums.size() - 1
    // Move left/right based on current sum.
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left < right) {
        const int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target){
            ++left;
        } else{
            --right;
        }
        }
    (void)nums;
    (void)target;
    return {-1, -1};
}

// Problem 2 (Sliding Window):
// Return the length of the longest substring without repeating chars.
// Example: "abcabcbb" -> 3 ("abc")
int longest_unique_substring(std::string_view s) {
    // TODO(day1): implement with sliding window + last seen index map.
    // O(n) target.
    std::unordered_map<char, int> last_seen;
    int left = 0;
    int max_len = 0;
    for (int right = 0; right <static_cast<int>(s.size()); ++right) {
        const char c = s[right];
        if (last_seen.count(c) > 0 && last_seen[c] >= left) {
            left = last_seen[c] + 1;
        }
        last_seen[c] = right;
        max_len = std::max(max_len, right - left + 1);
    }
    (void)s;
    return max_len;
}

bool run_tests() {
    bool ok = true;

    {
        const std::vector<int> nums{1, 2, 4, 7, 11, 15};
        const auto ans = two_sum_sorted(nums, 15); // 4 + 11
        if (!(ans.first == 2 && ans.second == 4)) {
            std::cout << "[FAIL] two_sum_sorted #1 expected (2,4), got ("
                      << ans.first << "," << ans.second << ")\n";
            ok = false;
        }
    }

    {
        const std::vector<int> nums{2, 3, 5, 9};
        const auto ans = two_sum_sorted(nums, 8); // 3 + 5
        if (!(ans.first == 1 && ans.second == 2)) {
            std::cout << "[FAIL] two_sum_sorted #2 expected (1,2), got ("
                      << ans.first << "," << ans.second << ")\n";
            ok = false;
        }
    }

    {
        const int ans = longest_unique_substring("abcabcbb");
        if (ans != 3) {
            std::cout << "[FAIL] longest_unique_substring #1 expected 3, got "
                      << ans << "\n";
            ok = false;
        }
    }

    {
        const int ans = longest_unique_substring("bbbbb");
        if (ans != 1) {
            std::cout << "[FAIL] longest_unique_substring #2 expected 1, got "
                      << ans << "\n";
            ok = false;
        }
    }

    {
        const int ans = longest_unique_substring("pwwkew");
        if (ans != 3) {
            std::cout << "[FAIL] longest_unique_substring #3 expected 3, got "
                      << ans << "\n";
            ok = false;
        }
    }

    {
        const int ans = longest_unique_substring("");
        if (ans != 0) {
            std::cout << "[FAIL] longest_unique_substring #4 expected 0, got "
                      << ans << "\n";
            ok = false;
        }
    }

    return ok;
}

int main() {
    std::cout << "Day1 Algorithm Lab\n";
    const bool ok = run_tests();
    if (!ok) {
        std::cout << "\nSome tests failed. Fill TODOs and run again.\n";
        return 1;
    }
    std::cout << "All tests passed.\n";
    return 0;
}

