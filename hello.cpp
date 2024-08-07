#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++) {
        int curr = arr[i], j = 0;
        for(j = i - 1; j >= 0; j--)
            if(arr[j] > curr)
                arr[j + 1] = arr[j];
            else
                break;

        arr[j + 1] = curr;
    }

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}