///Author: Pham Viet An
///Topics: Ad hoc Problems
///Problem: 4 - UVA483 - Word Scramble
///Language: C++

/*<-------------------------------------------------------------------------------------->*/

///Implement as the problem said

#include <bits/stdc++.h>

using namespace std;

char a[10000];
int n;

int main() {

    while (cin.getline(a,10000)) { ///Input to array of char a until end of file
        n = strlen(a); ///Get length of a

        int lastCharacter = -1; ///lastCharacter is for checking if there are
        for (int i = n-1; i >= 0; --i) ///more words to reverse
            if (a[i] != ' ') { ///check below for more understanding
                lastCharacter = i;
                break;
            }

        a[n] = ' '; ///make the last character as blank space
        for (int i = 0; i <= n; ++i) {
            if (a[i]!=' ') continue; ///iterate through all blank space

            for (int j = i-1; j >= 0 && a[j]!=' '; --j)
                cout << a[j]; ///at this blank space iterate backward to the last space to write it reversely

            if (i < lastCharacter) cout << " "; ///There are more words to reverse, so write out a blank space
            else cout << endl; ///There are no more word to write, so write down a line
        }
    }

    return 0;
}
