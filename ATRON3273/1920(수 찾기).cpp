#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool find_num(vector<long long>& arr, int num)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        //cout << left << " " << mid << " " << right << endl;

        if (arr[mid] == num)
        {
            return true;
        }
        else if (arr[mid] > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cin >> M;
    vector<long long> wanted(M);
    for (int i = 0; i < M; i++)
    {
        cin >> wanted[i];
    }
    
    for (int i = 0; i < M; i++)
    {
        cout << find_num(arr, wanted[i]) << "\n";
    }

    return 0;
}