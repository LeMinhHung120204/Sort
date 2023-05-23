#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int n, a[N];
int lomuto_partition(int *a, int l, int r)
{
    int x = a[r], i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}
int hoare_partition(int *a, int l, int r)
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (1)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
            return j;
    }
}
void lomuto_quicksort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int x = lomuto_partition(a, l, r);
    lomuto_quicksort(a, l, x - 1);
    lomuto_quicksort(a, x + 1, r);
}
void hoare_quicksort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int p = hoare_partition(a, l, r);
    hoare_quicksort(a, l, p);
    hoare_quicksort(a, p + 1, r);
}
int main()
{
    freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // lomuto_quicksort(a, 1, n);
    hoare_quicksort(a, 1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}