
int main()
{
    vector<vector<int>> tasks(5)(2);
    int l, h, ans = 0;
    int sumActual = 0, sumMinimum = INT_MIN;
    for (int i = 0; i < tasks.size(); i++)
    {
        sumActual += tasks[i][0];
        sumMinimum = tasks[i][1] >= sumMinimum ? tasks[i][1] : sumMinimum;
    }
    if (sumActual <= sumMinimum)
    {
        l = sumActual;
        h = sumMinimum;
    }
    else
    {
        l = sumMinimum;
        h = sumActual;
    }
    sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] - a[0] > b[1] - b[0]; });
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        int e = m;
        bool ok = 1;
        for (auto &t : tasks)
        {
            if (e < t[1])
            {
                ok = 0;
                break;
            }
            e -= t[0];
        }
        // if possible means we can do it in more less energy
        if (ok)
        {
            ans = m;
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}
