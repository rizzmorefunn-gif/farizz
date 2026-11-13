#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int jumlahGenap = 0;
    int jumlahGanjil = 0;

    cout << "Bilangan n = " ;
    cin>>n;

    for (int i = 1; i <= n; i++) {
        cout << i;
    }

    cout << "\nBilangan genap = ";
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            cout << i << ' ';
            jumlahGenap += i;
        }
    }

    cout << "\nBilangan ganjil = ";
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            cout << i << ' ';
            jumlahGanjil += i;
        }
    }

    cout << "\nJumlah bilangan genap = " << jumlahGenap;
    cout << "\nJumlah bilangan ganjil = " << jumlahGanjil << '\n';

    return 0;
}
