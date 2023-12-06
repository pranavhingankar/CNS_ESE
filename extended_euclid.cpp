#include <bits/stdc++.h>
using namespace std;

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int ansS, ansT;

int findGcdExtended(int r1, int r2, int s1, int s2, int t1, int t2)
{
    // Base Case
    if (r2 == 0)
    {
        ansS = s1;
        ansT = t1;
        return r1;
    }

    int q = r1 / r2;
    int r = r1 % r2;

    int s = s1 - q * s2;
    int t = t1 - q * t2;

    cout << q << " " << r1 << " " << r2 << " " << r << " " << s1 << " " << s2 << " " << s << " " << t1 << " " << t2 << " " << t << endl;

    return findGcdExtended(r2, r, s2, s, t2, t);
}

int main()
{
    // file();

    // 161 28

    int num1,
        num2, s, t;
    cout << "Enter 2 numbers to find GCD" << endl;
    cin >> num1 >> num2;

    cout << "Q"
         << " "
         << "r1"
         << " "
         << "r2"
         << " "
         << "r"
         << " "
         << "s1"
         << " "
         << "s2"
         << " "
         << "s"
         << " "
         << "t1"
         << " "
         << "t2"
         << " "
         << "t" << endl;

    int gcd = findGcdExtended(num1, num2, 1, 0, 0, 1);
    cout << "\n\nGCD = " << gcd << endl;
    cout << "S = " << ansS << endl;
    cout << "T = " << ansT << endl;

    return 0;
}

// 161 28