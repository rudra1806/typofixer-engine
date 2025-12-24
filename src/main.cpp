#include <iostream>     // cin, cout
#include <vector>       // vector
#include <string>       // string
#include <algorithm>    // min, sort, transform
#include <cmath>        // abs

#define threshold 3 // Maximum length difference for candidate words
using namespace std;


// Function to load dictionary words from a file into a vector
vector<string> load_dictionary(const string& filename);
int levenshtein_distance(const string &input,const string &target);

vector<string> find_suggestions(const string& input, const vector<string>& dictionary, int limit) {
    vector<pair<string, int>> candidates; // Pair of word and its distance

    for( const string& word : dictionary ){
        if(abs(int(word.size() - input.size())) > threshold) {
            continue; // prune words that differ too much in length 
        }
        int distance = levenshtein_distance(input, word);
        candidates.push_back({word, distance});
    }
    // Sort candidates based on distance
    sort(candidates.begin(), candidates.end(), [](const pair<string, int>& a, const pair<string, int>& b){
        if(a.second == b.second){
            return a.first < b.first; // If distances are equal, sort lexicographically
        }
        return a.second < b.second;
    });

    vector<string> suggestions;
    for(int i = 0; i < candidates.size() && i < limit ; ++i){
        suggestions.push_back(candidates[i].first);
    }

    return suggestions;
}


int main(){

    // Load dictionary from file
    vector<string> dictionary = load_dictionary("data/dictionary.txt");

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

        cout << "enter the limit for suggestions: ";
        int limit;
        cin >> limit;

        vector<string> suggestions = find_suggestions(input_word, dictionary, limit);

        cout << "Did you mean:" << endl;
        int i=1;
        for(const string& word : suggestions){
            cout << i << ". " << word << endl;
            i++;
        }
    }

    return 0;
}
