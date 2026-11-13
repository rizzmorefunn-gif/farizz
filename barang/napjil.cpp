#include <iostream>
using namespace std;

int main(){
    int n=0;
    int banyakgenap = 0;
    int banyakganjil = 0;

    cout << "Bilangan n = " ;
    cin>>n;

    for (int i = 1; i <= n; i++){
        cout << i;
    }

    cout << "\nBilangan genap =";
    for (int i = 1; i <= n; i++){
        if (i % 2 == 0){
    
            cout<<i<<""; 
            cout <<"\nbaynakgenap="<<banyakgenap;
        }
    }

    cout << "\nBilangan ganjil =";
    for (int i = 1; i <= n; i++){
        if (i % 2 != 0){
            cout << i << "";
            banyakganjil + + i;
        }
    }

    cout<<"\njumlah bilangan genap = "<<banyakgenap;
    cout<<"\njumlah bilangan ganjil = "<<banyakganjil;

    return 0;
}