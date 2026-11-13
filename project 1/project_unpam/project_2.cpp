#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    string nama;
    int tugas;
    int uas;
    int uts;
    int akhir;

    cout << "nama mahasiswa :";
    cin >> nama;

    cout << "nilai tugas:";
    cin >> tugas;

    cout << "uts :";
    cin >> uts;

    cout << "uas :";
    cin >> uas;

    akhir = (tugas + uas + uts)/3;

    double nilaiTertinggi = max(tugas, max(uas, uts));
    double nilaiTerendah =  min(tugas, min(uas, uts));

    int jumlahKarakterNama = nama.length();


    cout << "Nama            : " << nama << endl;
    cout << "Jumlah Karakter : " << jumlahKarakterNama << " karakter" << endl;
    cout << "nilai akhir : " << akhir << endl;
    cout << "Nilai Tertinggi : " << nilaiTertinggi << endl;
    cout << "Nilai Terendah  : " << nilaiTerendah << endl;

    
    return 0;




}