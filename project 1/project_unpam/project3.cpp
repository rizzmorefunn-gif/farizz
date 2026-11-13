#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define JUDUL_PRAKTIKUM "PRAKTIKUM DASAR PEMOFRAMAN C++"
#define DISKON_RATE 0.10

int main(){
    const float pi = 3.14159;
    string name;
    int jamKerja, jamLembur;
    double tarifperjam, gajipokok, uanglembur, totalgaji;

    cout << "===========" << endl;
    cout << "" << JUDUL_PRAKTIKUM <<endl;
    cout << "===========" << endl;

    cout << "masukan :";
    getline(cin, name);

    cout << "masukan jam kerja utama :";
    cin >> jamKerja;

    cout << "masukan jam kerja lembur :";
    cin >> jamLembur;

    cout << "masukan tarif per jam : Rp";
    cin >> tarifperjam;

   gajipokok = jamKerja * tarifperjam;
   uanglembur= jamLembur * (tarifperjam*1.5);
   totalgaji = gajipokok + uanglembur;

   double pajak = totalgaji * DISKON_RATE;
   totalgaji -= pajak;

   cout << "\n......................" << endl;
   cout << "    RONCIAN SLIP GAJI   " << endl;
   cout << "........................" << endl;
   cout << "prakitan :" << name << endl;
   cout << fixed << setprecision(2);
   cout << "gajipokok  :Rp"<<gajipokok<<endl; 
   cout << "uang lembur  :Rp"<<uanglembur<<endl; 
   cout << "pajak (10%)  :Rp"<<pajak<<endl; 
   cout << "............................."<<endl; 
   cout << "gaji bersih : Rp" << totalgaji << endl;
   cout << "............................."<<endl; 

   return 0;




}