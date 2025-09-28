#include <iostream>
using namespace std;

//tìm trung vị danh sách các số có số phần tử lẻ

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int MIN = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[MIN]) MIN = j;
        }
        if (MIN != i) swap(a[i], a[MIN]);
    }
    int median = a[n / 2];
    cout << median;
}
