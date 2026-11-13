#include <iostream>
using namespace std;


int main(){
    int jp,pilihan,harga,uang,kembalian;
    string np;
    int total;

    cout << "menu" << endl;
    cout << " 1 : mie ayam   15k"<< endl;
    cout << " 2 : nasi goreng  20k"<< endl;
    cout << " 3 : soto ayam  100k"<< endl;
    cout << " 4 : exit"<< endl;
    cout << endl;
    cout << "pilihan 1-4"<<endl;
    cin >> pilihan;

    switch (pilihan){
    
        case 1:
        np = "mie ayam";
        harga = 15000;
        break;

        case 2:
        np = "nasi goreng";
        harga = 20000;
        break;

        case 3:
        np = "soto ayam";
        harga = 100000;
        break;

        default:
        cout << "gak ada barang coy";
        return 0;
    }

    
    

    
    

    cout<< "jumlah pilihan" << pilihan << "masukan:";
    cin >> jp;

    if (jp<=0){
        cout << "error";
        return 0;
    }

    cout << "masukan uang";
    cin >> uang;

    total= harga*jp;
    kembalian = uang-total;

    if(uang < total){
        cout<< "uang kurang";
        return 0;
    }

    cout << " struk"<< endl;
    cout << "nama produk :" << np << endl;
    cout << "jumlah produk :" << jp << endl;
    cout << "harga satuan :"<< harga<<endl;
    cout << "total:"<<total<<endl;
    cout<<endl;
    cout<<"total:"<<total<<endl;
    cout<<"uang anda:"<<uang<<endl;
    cout<<"kembalian anda:"<<kembalian<<endl;
    cout<<endl;
    return 0;






    

    
}