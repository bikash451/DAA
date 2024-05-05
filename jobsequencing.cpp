#include<iostream>
using namespace std;

void merge(int *d, int *p, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int l[n1], r[n2], l1[n1], r1[n2];
    for (int i = 0; i < n1; i++) {
        l[i] = p[low + i];
        l1[i] = d[low + i];
    }
    for (int j = 0; j < n2; j++) {
        r[j] = p[mid + j + 1];
        r1[j] = d[mid + j + 1];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (l[i] > r[j]) {
            p[k] = l[i];
            d[k] = l1[i];
            i++;
            k++;
        } else {
            p[k] = r[j];
            d[k] = r1[j];
            j++;
            k++;
        }
    }
    while (i < n1) {
        p[k] = l[i];
        d[k] = l1[i];
        i++;
        k++;
    }
    while (j < n2) {
        p[k] = r[j];
        d[k] = r1[j];
        j++;
        k++;
    }
}

void mergesort(int *d, int *p, int low, int high) {
    if (low < high - 1) {
        int mid = (high + low) / 2;
        mergesort(d, p, low, mid);
        mergesort(d, p, mid + 1, high);
        merge(d, p, low, mid, high);
    }
}

int jobscheduler(int *d, int *p) {
    int a[5] = {0};
    int res = 0;
    int j;
    for (int i = 0; i < 5; i++) {
        j = d[i];
        while (j > 0) {
            if (a[j] == 0) {
                a[j] = 1;
                res += p[i];
                break;
            } else {
                j--;
            }
        }
    }
    return res;
}

int main() {
    int deadline[5] = {2, 1, 2, 1, 3};
    int profit[5] = {100, 19, 27, 25, 15};
    mergesort(deadline, profit, 0, 5);
    for (int i = 0; i < 5; i++) {
        cout << deadline[i] << "\t" << profit[i] << endl;
    }
    cout << jobscheduler(deadline, profit);
    return 0;
}
