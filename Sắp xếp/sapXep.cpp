#include <bits/stdc++.h>
using namespace std;

// tim kiem nhi phan phai lam trn day da sap xep
int binary_search(int x[], int left, int right, int k)
{
    int mid = 0;
    if (left > right)
        return -1;
    else
    {
        mid = (left + right) / 2;
        if (x[mid] == k)
            return mid;
        else
        {
            if (x[mid] < k)
                return binary_search(x, mid + 1, right, k);
            else
                return binary_search(x, left, mid - 1, k);
        }
    }
}
// int binary_search(const std::vector<int>& arr, int target) {
//     int left = 0;
//     int right = arr.size() - 1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;

//         if (arr[mid] == target) {
//             return mid;
//         }
//         else if (arr[mid] < target) {
//             left = mid + 1;
//         }
//         else {
//             right = mid - 1;
//         }
//     }

//     return -1; // Trả về -1 nếu không tìm thấy target trong mảng
// }

int binary_search_recursive(int arr[], int target, int left, int right)
// đệ quy tìm kiếm nhị phân
{
    

    if (left > right)
    {
        return -1; // Trả về -1 nếu không tìm thấy target trong mảng
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binary_search_recursive(arr, target, mid + 1, right);
    }
    else
    {
        return binary_search_recursive(arr, target, left, mid - 1);
    }
}
// sap xep chen
void insertionSort(int x[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = x[i];
        int j = i - 1;
        while (j > -1 && x[j] > temp)
        {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = temp;
    }
}
// sap xep lua chon
void selectionSort(int x[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int p = i;
        for (int j = i + 1; j < n; j++)
        {
            if (x[j] < x[i])
                p = j;
        }
        x[p] += x[i];
        x[i] = x[p] - x[i];
        x[p] -= x[i];
    }
}
// sap xep noi bot
void bubbleSort(int x[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (x[j] < x[j - 1])
            {
                int tg = x[j];
                x[j] = x[j - 1];
                x[j - 1] = tg;
            }
}

int main()
{
    int n, k;
    cin >> n;

    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cin >> k;
    // insertionSort(x, n); // sap xep chen
    // sort(x, x+n); // sap sep co san
    bubbleSort(x, n);
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    //    cout<< binary_search(x, 0, n-1, k)<<endl;
    //    cout<<binary_search_recursive(x, k, 0, n - 1);
}