#include<iostream>
#include<cmath>

using namespace std;
int main(){
    float alas,tinggi,hipotenusa;
    cout << "---hitung sisi miring segi tiga"<<endl;
    cout << "masukan alas :";
    cin >> alas;
    cout <<" masukan Tinggi :";
    cin >> tinggi;
    hipotenusa=sqrt(pow(alas,2)+pow(tinggi,2));
    cout << "panjang sisi miring ( hipotenusa) adalah:"<< hipotenusa << endl;
    return 0;
}
