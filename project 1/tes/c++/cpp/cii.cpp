#include <iostream>
using namespace std;

int maint(){

    string barang;
    int harga;
    int jumlah;
    int total;

    cout << "nama Barang";
    cin >> barang;

    cout << "Harga Barang";
    cin >> harga;

    cout << "Jumlah Beli";
    cin >> jumlah;

    total = harga * jumlah;

    cout << endl;
    cout << "===== STRUK PEMBELIAN =====" << endl;
    cout << "Barang : " << barang << endl;
    cout << "Total Bayar :" << total << endl;

    return 0;
}