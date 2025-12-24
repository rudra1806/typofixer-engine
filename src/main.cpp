#include <iostream>     // cin, cout
#include <fstream>      // ifstream (file reading)
#include <vector>       // vector
#include <string>       // string
#include <algorithm>    // min, sort, transform
#include <cmath>        // abs

using namespace std;

// Function to load dictionary words from a file into a vector
vector<string> load_dictionary(const string& filename);
int levenshtein_distance(const string &input,const string &target);

vector<string> find_suggestions(const string& input, const vector<string>& dictionary){
    vector<pair<string, int>> candidates; // Pair of word and its distance

    for( const string& word : dictionary ){
        int distance = levenshtein_distance(input, word);
        if(distance <= 3){ // Threshold for suggestions
            candidates.push_back({word, distance});
        }
    }
}


int main(){

    // Load dictionary from file
    vector<string> dictionary = load_dictionary("../data/dictionary.txt");

    cout << "Dictionary is Loaded with " << dictionary.size() << " words." << endl;

    string input_word;
    cout << "Enter a word to check: ";
    cin >> input_word;

    // Transform the input word to lowercase for case-insensitive comparison
    transform(input_word.begin(), input_word.end(), input_word.begin(), ::tolower);

    // Check if the input word is in the dictionary
    if(find(dictionary.begin(), dictionary.end(), input_word) != dictionary.end()){
        cout << input_word << " is spelled correctly." << endl;
    } else {
        cout << input_word << " is misspelled." << endl;
        cout << "Did you mean:" << endl;

        vector<string> suggestions = find_suggestions(input_word, dictionary);
        for(const string& word : suggestions){
            cout << "  " << word << endl;
        }
    }

    return 0;
}
