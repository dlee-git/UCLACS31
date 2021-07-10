#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int scoreTypo(const string dictionary[], int n, string word)
{
    // n is not positive, scoreTypo returns −1
    if (n < 1) {
        return -1;
    }

    // check if the strings are identical
    for (int i = 0; i < n; i++) {
        if (dictionary[i] == word) {
            return 0;
        }
    }

    int typoCount = 0;   // keep count of number of typos
    int wordLength = word.size();
    int stringLength = 0;

    //// Simple Typos
    for (int i = 0; i < n; i++) {
        stringLength = dictionary[i].size();

        // check if replacing exactly one character in the string
        if (wordLength == stringLength) {
            for (int k = 0; k < wordLength; k++) {
                if (word.at(k) != dictionary[i].at(k)) {
                    typoCount++;
                }
            }
        }

        // check if adding exactly one character to the string
        if (wordLength == stringLength + 1) {
            typoCount++;
            for (int j = 0; j < stringLength; j++) {
                if ((word.at(j) != dictionary[i].at(j)) && (word.at(j + 1) != dictionary[i].at(j))) {
                    typoCount++;
                }
            }
        }
        
        // removing exactly one character from the string
        if (wordLength + 1 == stringLength) {
            typoCount++;
            for (int l = 0; l < wordLength; l++) {
                if ((word.at(l) != dictionary[i].at(l)) && (word.at(l) != dictionary[i].at(l + 1))) {
                    typoCount++;
                }
            }
        }

        // check if swapping two adjacent characters in the string
        if (wordLength == stringLength && typoCount == 2) {
            for (int m = 0; m < wordLength - 1; m++) {
                if (word.at(m) != dictionary[i].at(m) && word.at(m+1) != dictionary[i].at(m+1)) {
                    if (word.at(m) == dictionary[i].at(m + 1) && word.at(m + 1) == dictionary[i].at(m)) {
                        typoCount--;
                    }
                }
            }
        }

        // If a simple typo
        if (typoCount == 1) {
            return 1;
        }
        typoCount = 0;
    }

    return 2;
}

int main()
{
    // Here are some tests.  You may add more if you wish.
    string dict1[7] = { "february", "pointer", "country", "forty", "conversation", "minuscule", "apple" };
    assert(scoreTypo(dict1, 0, "forty") == -1);
    assert(scoreTypo(dict1, 6, "forty") == 0);
    assert(scoreTypo(dict1, 6, "fourty") == 1);
    assert(scoreTypo(dict1, 6, "febuary") == 1);
    assert(scoreTypo(dict1, 6, "miniscule") == 1);
    assert(scoreTypo(dict1, 6, "poitner") == 1);
    assert(scoreTypo(dict1, 6, "conservation") == 2);
    assert(scoreTypo(dict1, 7, "appple") == 1);
    cout << "All tests succeeded" << endl;
}
