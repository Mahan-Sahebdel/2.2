#include<iostream>
#include<conio.h>
#define N 6
bool ispeak(int i, int arr[]) {
    if (i != 0 && i != N - 1)

        if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
            return true;
        else if (i == 0)
            if (arr[i + 1] < arr[i])
                return true;

            else if (i == N - 1)
                if (arr[i - 1] < arr[i])
                    return true;

    return false;

}
int solve(int arr[], int i, int j) {
    if (i == j) {
        return i;
    }
    else if (i + 1 == j) {
        if (ispeak(i, arr)) return i;
        return j;
    }
    else {
        int m = (i + j) / 2;
        if (ispeak(m, arr)) {
            return m;
        }
        else if (arr[m - 1] > arr[m] && arr[m] > arr[m + 1]) {
            return solve(arr, i, m - 1);
        }
        else {
            return solve(arr, m + 1, j);
        }
    }
}
main() {

    int arr[] = { 1,3,20,4,1,0 };
    if (!solve(arr, 0, 5))
        std::cout << "no such i";
    else
        std::cout << solve(arr, 0, 5);
}
