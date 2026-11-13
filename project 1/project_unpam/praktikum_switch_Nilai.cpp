#include <iostream>
using namespace std;

int main(){
    char nilai;

    cout<<"=======NILAI MAHASISWA====="<<endl;
    cout<<"A.Sangat Baik"<<endl;
    cout<<"B. Baik"<<endl;
    cout<<"C. Cukup"<<endl;
    cout<<"D.kurang"<<endl;
    cout<<"E.Sangat Surang"<<endl;

    cout<<"Masukan nilai  :";
    cin>> nilai;

    switch(nilai){
    case 'A':
    case 'a':
    cout<<"Sangat Baik";
    break;

    case 'B':
    case 'b':
    cout<<"Baik";
    break;

    case 'C':
    case 'c':
    cout<<"Cukup";
    break;

    case 'D':
    case 'd':
    cout<<"Kurang";
    break;

    case 'E':
    case 'e':
    cout<<"Sangat Kurang";
    break;

    default:
    cout<<"Nilai tidak valid.";
}
return 0;    
}