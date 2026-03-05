#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <string>
#include "s4.h"
using namespace std;

// 测试用例结构
struct TestCase {
    string input;
    string expected;  // 可选：预期结果
};

// 所有测试数据
class Data {
public:
    // 获取测试用例列表
    static vector<TestCase> getTestCases() {
        return {
            {"babad", "bab"},   // 或 "aba"
            {"cbbd", "bb"},
            {"a", "a"},
            {"ac", "a"},
            {"racecar", "racecar"},
            // 添加更多测试用例...
        };
    }

    // 获取单个测试字符串（用于简单场景）
    static string getSingleInput() {
        return "babad";
    }

    // 运行所有测试并输出结果
    static void runAllTests() {
        Solution sol;
        vector<TestCase> cases = getTestCases();

        cout << "=== 运行 " << cases.size() << " 个测试用例 ===" << endl;

        for (int i = 0; i < (int)cases.size(); i++) {
            const auto& tc = cases[i];
            string result = sol.longestPalindrome(tc.input);
            bool pass = (result == tc.expected ||
                (tc.expected == "bab" && result == "aba")); // 特殊情况处理

            cout << "测试 " << i + 1 << ": " << endl;
            cout << "  输入:    \"" << tc.input << "\"" << endl;
            cout << "  输出:    \"" << result << "\"" << endl;
            cout << "  期望:    \"" << tc.expected << "\"" << endl;
            cout << "  结果:    " << (pass ? "PASS" : "FAIL") << endl << endl;
        }
    }

    // 运行单个测试
    static void runSingleTest(const string& input) {
        Solution sol;
        cout << "输入:  \"" << input << "\"" << endl;
        cout << "输出:  \"" << sol.longestPalindrome(input) << "\"" << endl;
    }
};

#endif // DATA_H