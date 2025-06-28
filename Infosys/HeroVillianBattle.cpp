#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M, H;
    cin >> N >> M >> H;
    vector<int> V(N);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }

    int currHealth = H;
    int i = N - 1;
    while (i >= 0)
    {
        if (currHealth > V[i])
        {
            currHealth -= V[i];
            i--;
        }
        else if (currHealth == V[i])
        {
            M--;
            i--;
            if (M == 0)
                break;
            currHealth = H;
        }
        else
        {
            M--;
            if (M == 0)
                break;
            currHealth = H;
        }
    }
    cout << i + 1 << endl;
    return 0;
}
