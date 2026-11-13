#include <iostream>
using namespace std;

int main(){
    int pilihan;
    float angka1, angka2, hasil;

    cout<<"======MENU OPRASI====="<<endl;
    cout<<"1.penjumlahaan"<<endl;
    cout<<"2.pengurangan"<<endl;
    cout<<"3.perkaliaan"<<endl;
    cout<<"4.pembagian"<<endl;

    cout<<"pilihan menu:";
    cin >> pilihan;

    cout<<"masukan bilangan pertama :";
    cin>>angka1;

    cout<<"masukan bilangan kedua :";
    cin>> angka2;

    switch (pilihan){
        case 1:
        hasil=angka1+angka2;
        cout<< "hasil="<<hasil;
        break;

        case 2:
        hasil=angka1-angka2;
        cout<< "hasil="<<hasil;
        break;

        case 3:
        hasil=angka1*angka2;
        cout<< "hasil="<<hasil;
        break;

        case 4:
        if (angka2 !=0){
            hasil=angka1/angka2;
            cout<<"hasil="<<hasil;
        }else{
            cout<<"tidak dapat membagi dengan nol.";
        }
        break;

        default:
        cout<<"pilohan tidak tersedia.";

        return 0;

    
    }

}