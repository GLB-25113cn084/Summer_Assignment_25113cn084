#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    char vowels[] = "aeiouAEIOU";
    int vowelCount = 0, consonantCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            bool isVowel = false;

            for (int j = 0; vowels[j] != '\0'; j++) {
                if (ch == vowels[j]) {
                    isVowel = true;
                    break;
                }
            }
            if (isVowel) vowelCount++;
            else consonantCount++;
        }
    }
    cout << "Vowels: " << vowelCount << endl;
    cout << "Consonants: " << consonantCount << endl;
    return 0;
}
