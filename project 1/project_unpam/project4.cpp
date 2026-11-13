#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

#define NAMA_TOKO "TOKO BUKU MAHASISWA"
#define BIAYA_ADMIN 2500


int main(){
    const double PAJAK_RATE = 0.11;
    string namapembeli,namabarang;
    int jumlahbeli;
    double hargasatuan,totalkotor,nilaipajak,totalbersih;

    cout << "======================" << endl;
    cout << "" << NAMA_TOKO <<endl;
    cout << "======================" << endl;

    cout << "nama pembeli :";
    getline(cin, namapembeli);

    cout << "nama BUKU/BARANG:";
    getline(cin, namabarang);

    cout << "harga satuan :";
    cin >> hargasatuan;

    cout << "jumlah beli : Rp";
    cin >> jumlahbeli;

    totalkotor= hargasatuan * jumlahbeli;
    nilaipajak= totalbersih * PAJAK_RATE;
    totalbersih= totalkotor * nilaipajak;
    totalbersih -= BIAYA_ADMIN;

     cout << "\n......................" << endl;
   cout << "    strip pembayar   " << endl;
   cout << "........................" << endl;
   cout << "pelanggan :" << namapembeli << endl;
   cout << "barang  :"<<namabarang<<endl; 
   cout << "jumlah  :"<<jumlahbeli<<endl;

   cout << fixed << setprecision(2);
    
   cout << "total sub  :Rp"<<totalkotor<<endl; 
   cout << "pajak (11%):Rp"<<nilaipajak<<endl; 
   cout << "BIAYA ADMIN  :Rp"<<(double)BIAYA_ADMIN<<endl;
   
   cout << "........................" << endl;
   cout << "pajak (10%)  :Rp"<<totalbersih<<endl;
   cout << "........................" << endl;
    

   return 0;

}