#include <bits/stdc++.h>
using namespace std;
int main()
{
    int E;
    cin >> E;
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (E <= 0)
        {
            break;
        }
        if (E > A[i])
        {
            E -= 2 * A[i];
            count += 2;
        }
        else
        {
            E -= A[i];
            count++;
        }
    }
    if (E > 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << count << endl;
    }
    return 0;
}