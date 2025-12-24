#include <iostream>     // cin, cout
#include <fstream>      // ifstream (file reading)
#include <vector>       // vector
#include <string>       // string
#include <algorithm>    // min, sort, transform
#include <cmath>        // abs

using namespace std;

// Function to load dictionary words from a file into a vector
vector<string> load_dictionary(const string& filename);

int main(){

    // Load dictionary from file
    vector<string> dictionary = load_dictionary("../data/dictionary.txt");

    cout << "Dictionary is Loaded with " << dictionary.size() << " words." << endl;

    string input_word;
    cout << "Enter a word to check: ";
    cin >> input_word;

    // Transform the input word to lowercase for case-insensitive comparison
    transform(input_word.begin(), input_word.end(), input_word.begin(), ::tolower);
    
    return 0;
}
