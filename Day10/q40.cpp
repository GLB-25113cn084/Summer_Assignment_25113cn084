#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch='A';
        for (int j = 1; j <= n - i; j++)
            cout << " ";

        for (int j = 1; j <= i; j++)
        {
            cout << ch ; 
            ch++;        
        }

        ch=ch-2;
        for (int j=i-1; j>=1; j--)
        {
            cout << ch ;
            ch--;         
        }
        
        cout << endl;
    }   
}