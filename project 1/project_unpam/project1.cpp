#include <iostream>
using namespace std;

int main() {
    string nama;
    int harga;
    int jumlah;
    int bayar;
    int subtotal;
    int total;
    int diskon = 0;
    int kembalian;

    cout << "Nama barang :";
    cin >> nama;

    cout << "harga barang :";
    cin >> harga;

    cout << "jumlah barang :";
    cin >> jumlah;

    cout << "bayar :";
    cin >> bayar;

    subtotal= harga * jumlah;

    if (subtotal >= 100000){
        diskon = 0.10 * subtotal;
    }
    else if (subtotal >= 50000){
        diskon = 0.05 * subtotal;
    }
    else {
        diskon = 0;
    }

    total=subtotal - diskon;
    kembalian = bayar - total;
    
    cout << "\n===== struk pembelanjaan ====="<< endl;
    cout << "Nama barang   :"  << nama << endl;
    cout << "harga barang    :"  << harga << endl;
    cout << "jumlah barang :"  << jumlah << endl;
    cout << "bayar :"  << bayar << endl;
    cout << "subtotal   :"  << subtotal << endl;
    cout << "diskon    :"  << diskon <<  endl;
    cout << "total :"  << total << endl;
    cout << "kembalian :"  << kembalian << endl;

    return 0;

}