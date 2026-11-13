#include <iostream>
using namespace std;

int main() {

    const float PAJAK = 0.11;

    string namabarang = "keyboard";
    int harga = 150000;
    int jumlah = 2;

    int subtotal = harga * jumlah;
    float nilaipajak = subtotal * PAJAK;
    float total = subtotal + nilaipajak;

    cout << "===== TRANSAKSI =====" << endl;
    cout << "Barang     : " << namabarang << endl;
    cout << "harga      : " << harga << endl;
    cout << "Jumlah     : " << jumlah << endl;
    cout << "Subtotal   : " << subtotal << endl;
    cout << "pajak      : " << nilaipajak << endl;
    cout << "Total      : " << total << endl;

    return 0;
}