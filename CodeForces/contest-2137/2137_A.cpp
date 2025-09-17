/*
 * -----------------------------------------------------------------------------
 * //  Copyright (c) 2025 Vanishing Games. All Rights Reserved.
 * @Author: VanishXiao
 * @Date: 2025-09-17 15:44:00
 * @LastEditTime: 2025-09-17 17:08:15
 * -----------------------------------------------------------------------------
 */
#include <iostream>
using namespace std;

int Solve(int k, int x)
{
    return x << k;
}

int main()
{
    cout << "Hello, C++!" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        cin >> k >> x;
        cout << Solve(k, x) << endl;
    }
    return 0;
}
/*
input:
1
3 2
output:
cpp: 16
cs: 16
fs: 16
expected:
cpp: 16
cs: 4
fs: 8
*/