#include <iostream>
using namespace std;
int main(){
    int pilihan;

    do {
        cout << "\n====Menu Pilihan==== " << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Keluar " << endl;
        cout << "Masukkan pilihan Anda: ";        
        cin >> pilihan;

         if(pilihan==1){
        cout<<"data mahasiswa ditampilkan."<<endl;

     }
     else if (pilihan ==2){
        cout<<"data mahasiswa di tambahkan"<<endl;
     }
     else if (pilihan ==3){
        cout << "program selesai"<<endl;
     }
     else{
        cout<<"pilihan tidak tersedia"<<endl;
    }
    while (pilihan !=3);
    return 0;
}
