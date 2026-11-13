#include<iomanip>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
    string prodi = "teknik informatika";
    cout << prodi.length() << endl;
    cout << prodi.substr(0,6)<<endl;
    cout << prodi.find("info");
    return(0);
}