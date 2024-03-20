#include <iostream>
using namespace std;

void QuickSort(int A[], int i, int j);

int Partisi(int A[], int i, int j) {
    int pivot = A[(i + j) / 2]; // Pilih pivot (biasanya elemen tengah)
    int p = i; // Awal pemindaian dari kiri
    int q = j; // Awal pemindaian dari kanan

    while (p <= q) {
        while (A[p] < pivot)
            p++;
        while (A[q] > pivot)
            q--;
        if (p <= q) {
            // Pertukarkan A[p] dengan A[q]
            int temp = A[p];
            A[p] = A[q];
            A[q] = temp;
            p++;
            q--;
        }
    }

    return p;
}

void QuickSort(int A[], int i, int j) {
    if (i < j) { // Ukuran(A) > 1
        int k = Partisi(A, i, j); // Larik dipartisi pada indeks k
        QuickSort(A, i, k - 1); // Urut A[i..k-1] dengan Quick Sort
        QuickSort(A, k, j); // Urut A[k..j] dengan Quick Sort
    }
}

int main() {
    int larik[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(larik) / sizeof(larik[0]);

    QuickSort(larik, 0, n - 1);

    cout << "Larik setelah diurutkan: ";
    for (int i = 0; i < n; i++)
        cout << larik[i] << " ";
    cout << endl;

    return 0;
}
