#include <iostream>     // cin, cout
#include <fstream>      // ifstream (file reading)
#include <vector>       // vector
#include <string>       // string
#include <algorithm>    // min, sort, transform
#include <cmath>        // abs

using namespace std;

vector<string> load_dictionary(const string &filename){
    vector<string> dictionary;
    ifstream file(filename); // Open the file for reading
    if(file.is_open()){
        string word;
        while(file >> word){
            // Transform the word to lowercase for case-insensitive comparison
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            // Add each word to the dictionary vector
            dictionary.push_back(word);
        }
        // Close the file after reading
        file.close();
    } else {
        cerr << "Error: Could not open the dictionary file." << endl;
    }
    return dictionary;
}