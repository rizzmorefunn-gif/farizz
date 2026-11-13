#include <iostream>
using namespace std;

int main(){
 int nilai, total =0;
 for(int i=1; i<=5;i++ ) 
 {
    cout << "masukan nilai ke-" << i << " : ";
   cin >> nilai;
   total += nilai;
 }
  
 double ratarata = (double) total / 5;
 cout << "Total: " << total << endl;
 cout<<"rata-rata="<<ratarata;
 return 0;
 
    

 
}
