#include <iostream>
#include <string>

using namespace std;

int main() {
    int pilihan, jumlah;
    string namaProduk = "";
    int harga = 0;
    
    cout << "=== MENU KASIR SERBA ADA ===" << endl;
    cout << "1. Kopi  - Rp 15.000" << endl;
    cout << "2. Teh   - Rp  8.000" << endl;
    cout << "3. Roti  - Rp 10.000" << endl;
    cout << "4. Keluar" << endl;
    cout << endl;
    cout << "Pilih menu (1-4): ";
    cin >> pilihan;

    
    switch (pilihan) {
        case 1:
            namaProduk = "Kopi";
            harga = 15000;
            break;
        case 2:
            namaProduk = "Teh";
            harga = 8000;
            break;
        case 3:
            namaProduk = "Roti";
            harga = 10000;
            break;
        case 4:
            cout << "Terima kasih telah membeli di toko kami!!!!" << endl;
            return 0;
        default:
            cout << "gak ada barang cuy!!!" << endl;
            return 0;
    }

    cout << "Masukkan jumlah " << namaProduk << " yang dibeli: ";
    cin >> jumlah;

    int totalPembayaran = harga * jumlah;

    cout << "\n=== STRUK PEMBAYARAN ===" << endl;
    cout << "Nama Produk : " << namaProduk << endl;
    cout << "Harga Satuan: Rp " << harga << endl;
    cout << "Jumlah Beli : " << jumlah << endl;
    cout << "==================" << endl;
    cout << "Total Bayar : Rp " << totalPembayaran << endl;
    cout << "==================" << endl;

    return 0;
}