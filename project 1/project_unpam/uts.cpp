#include <iostream>
using namespace std;

int main(){
    string namamah,nbarang;
    int harga,jb,pilihan,uang,kembalian;
    int total;

    cout<<"masukan nama:";
    cin>>namamah;
    
    cout<<endl;
    cout<<"nama mahasiswa:"<<namamah<<endl;
    cout<<endl;
    cout<<"=====menu makanan===="<<endl;
    cout<<endl;
    cout<<"1 Mie Ayam :10.000"<<endl;
    cout<<"2 Cihcken Katsu :15.000"<<endl;
    cout<<"3 Ayam Geprek :20.000"<<endl;
    cout<<"4 exit"<<endl;
    cout<<"========================"<<endl;
    cout<<"pilihmenu 1-4"<<endl;
    cout<<"silakan masukan pesanan anda:";
    cin>>pilihan;
    

    switch (pilihan){
    case 1:
    nbarang="Mie Ayam";
    harga=10000;
    break;

    case 2:
    nbarang="Chicken Katsu";
    harga=15000;
    break;

    case 3:
    nbarang="Ayam Geprek";
    harga = 20000;
    break;

    case 4:
    nbarang="exit";
    return 0;
    }
    
    cout<<"masukan jumlah pesanan anda:";
    cin>>jb;
    

    total=harga*jb;

    cout<<"=========="<<endl;
    cout<<"harga satuan:"<<harga<<endl;
    cout<<"jumlah barang:"<<jb<<endl;
    cout<<"total bayar"<<total<<endl;
    cout<<"==========="<<endl;

    cout<<"masukan uang costumer:";
    cin>>uang;

    kembalian=uang-total;

    cout<<"=========="<<endl;
    cout<<"nama:"<<namamah<<endl;
    cout<<"total bayar:"<<total<<endl;
    cout<<"uang bayar:"<<uang<<endl;
    cout<<"uang kembalian:"<<kembalian<<endl;
    cout<<"==========="<<endl;
    cout<<"TERIMA KASIH"<<endl;
    cout<<"==========="<<endl;







    

}