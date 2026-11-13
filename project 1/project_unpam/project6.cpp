#include <iostream>
using namespace std;

int main() {
    string barang;
    int harga;
    int jumlah;
    int total;


    cout << "masukan barang: ";
    cin >> barang;

    cout << "masukan harga barang :";
    cin >> harga;

    cout << "masukan jumlah beli :";
    cin >> jumlah;

    total=harga*jumlah;

    cout << endl;
    cout << "nama barang   :"  << barang << endl;
    cout << "total bayaar    :"  << total<< endl;

    return 0;
    


}