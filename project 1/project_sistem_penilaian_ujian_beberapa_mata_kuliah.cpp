#include <iostream>
using namespace std;

int main(){
    string nama;
    int tugas, uas, uts, project;
    int total;

    cout << "Nama Mahasiswa :";
    cin >> nama;

    cout << "Nilai Tugas :";
    cin >> tugas;

    cout << "Nilai project :";
    cin >> project;

    cout << "Nilai UTS :";
    cin >> uts;

    cout << "Nilai Uas :";
    cin >> uas;

    total= tugas + project + uts + uas;

    cout << endl;
    cout << "Nama :" << nama << endl;
    cout << "Total Nilai :" << total << endl;

    return 0;

    
}