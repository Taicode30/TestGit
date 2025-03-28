#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    int tich = 1;
    for (int i = 0; i <= n; i++){
        if (i%2 == 0)
            tich *= i;
    }
    cout << tich;
}