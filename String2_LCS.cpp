#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, k;
    cout << "Enter First String (x): ";
    cin >> s;
    cout << "Enter Second String (y): ";
    cin >> k;

    // Determine the length of the strings 's' and 'k'
    const int M = s.length();
    const int N = k.length();

    vector<vector<int>> arr(M+2, vector<int>(N+2, 0)); 

    // Fill the 2D array according to the LCS algorithm
    for (int i = 2; i <= M+1; ++i) {
        for (int j = 2; j <= N+1; ++j) {
            if (s[i-2] == k[j-2]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            } else {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    // Create a 2D vector of char for printing purposes
    vector<vector<char>> display(M+2, vector<char>(N+2, ' '));
    
    // Fill the display vector with characters from the strings
    for (int i = 2; i <= M+1; ++i) {
        display[i][0] = s[i-2];
    }
    for (int j = 2; j <= N+1; ++j) {
        display[0][j] = k[j-2];
    }
    
    // Printing out the table
    for (int i = 0; i <= M+1; ++i) {
        for (int j = 0; j <= N+1; ++j) {
            if (i == 0 || j == 0) {
                cout << display[i][j] << "\t";
            } else {
                cout << arr[i][j] << "\t";
            }
        }
        cout << endl;
    }

    // Length of the longest common subsequence
    cout << "\nThe ans is: " << arr[M+1][N+1] << endl;

    return 0;
}
