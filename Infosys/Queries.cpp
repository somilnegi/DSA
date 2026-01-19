#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < q; i++)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        int k = 0;
        for (int j = l; j <= r; j++)
        {
            A[j] = x + (k * y);
            k++;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    cout << sum << endl;
    return 0;
}