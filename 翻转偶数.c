#include <iostream>
using namespace std;

int flipNum(int x)
{
    if (x & 1) return x;
    int n = 0;
    while (x)
    {
        n = (n << 1) | (x & 1);
        x = x >> 1;
		printf("\nn is %d, x is %d\n", n, x);
    }
    return n;
}
int main()
{
    int N;
    int x;
    while (cin >> N)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> x;
            cout << flipNum(x);
            if (i != N - 1) cout << " ";
        }
        cout << endl;
    }
}