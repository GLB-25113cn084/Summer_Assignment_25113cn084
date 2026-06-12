#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout<<"enter a number to find its factorial: ";
    cin>>n;
    if (n < 0) {
        cout<<"factorial is not defined for negative numbers"<<endl;
        return 0;
    }
    cout<<"the factorial of "<<n<<" is: "<<factorial(n)<<endl;
    return 0;
}