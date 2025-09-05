/*
 * // -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-08-25 16:10:44
 * @LastEditTime: 2025-09-05 14:45:22
 * // -----------------------------------------------------------------------------
 */
#include "iostream"
#include "vector"

using namespace std;
/*
 * @lc app=leetcode.cn id=2523 lang=cpp
 *
 * [2523] 范围内最接近的两个质数
 */

// @lc code=start
class Solution
{
public:
    vector<int> CalcuPrimeNumbersBetween(const int &left, const int &right)
    {
        vector<int> primeNumbers = vector<int>();

        for (int i = left; i <= right; i++)
        {
            bool isPrimeNum = true;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    isPrimeNum = false;
                    break;
                }
            }

            if (isPrimeNum)
                primeNumbers.emplace_back(i);
        }

        return primeNumbers;
    }

    vector<int> closestPrimes(int left, int right)
    {
        auto primeNumbers = CalcuPrimeNumbersBetween(left, right);

        if(primeNumbers.size() <=1)
            return {-1,-1};
        
        for(int i = 1; i < primeNumbers.size(); i++)
        {
            
        }
    }
};
// @lc code=end

int main()
{
    int left = 10, right = 19;
    Solution s;
    auto vec = s.CalcuPrimeNumbersBetween(10, 19);
    for (auto i : vec)
        cout << " " << i;
    cout << endl;
}