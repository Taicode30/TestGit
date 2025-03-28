#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    int tich = 1;
    do {
        cout << "Nhap n: ";
        cin >> n;
        if (n<1){
            cout << "Moi ban nhap lai" << endl;
        }
    }
    while (n<1);

    for (int i=1; i<=n; i++){
        tich *= i;
    }
    cout << "Answer: " << fixed << setprecision(10) << tich;
}