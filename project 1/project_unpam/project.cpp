#include <iostream>
using namespace std;

int main() {
    string nama;
    int gaji;
    int tunjangan;
    int potongan;
    int total;

    cout << "Nama karyawan :";
    cin >> nama;

    cout << "Gaji Pokok :";
    cin >> gaji;

    cout << "Tunjangan :";
    cin >> tunjangan;

    cout << "potongan :";
    cin >> potongan;

    total= gaji + tunjangan - potongan;

    cout << "\n===== SISTEM GAJI KARYAWAN ====="<< endl;
    cout << "Nama Karyawan   :"  << nama << endl;
    cout << "Gaji pokok    :"  << gaji << endl;
    cout << "Tunjangan :"  << tunjangan << endl;
    cout << "Potongan :"  << potongan << endl;

    return 0;

}