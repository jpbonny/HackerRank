/*
Min Edit Distance by Jean-Paul Bonny
This is an implementation of the min edit distance algorithm that uses memoization, a build up approach, to
   finding how similar two strings are. It is a dynamic programming approach that will record the
   largest common substring size that each string can from with zero or more edits.

input (two strings):
JOHN
JOANNA

output (length of max common segment):
3 ( deleting the 'H' in JOHN and 'A' in JOANNA gives us 'JON', which is the largest common substring between the two inputs)
*/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    const int MAX_SIZE = 5001;
    static int table[MAX_SIZE][MAX_SIZE];
    getline(cin, a);
    getline(cin, b);
    for(int i = 0; i <= a.length(); i++) table[i][0] = 0;
    for(int j = 0; j <= b.length(); j++) table[0][j] = 0;
    for(int i = 0; i < a.length(); i++) {
        for(int j = 0; j < b.length(); j++) {
            // if characters match, increment largest common substring count by one
            if(a[i] == b[j])
                table[i+1][j+1] = table[i][j] + 1;
            // else move the largest common substring count to the next index
            else
                table[i+1][j+1] = max(table[i+1][j], table[i][j+1]);
        }
    }
    // print out the largest common substring value, stored at the indices of the strings' respecive sizes
    cout << table[a.length()][b.length()] << endl;
    return 0;
}
