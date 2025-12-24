# TypoFixer-Engine 

A fast and lightweight **spell-correction engine** written in **C++**, designed to detect misspelled words and suggest the closest valid alternatives using the **Levenshtein Distance algorithm** .

This project demonstrates clean code structure, algorithmic thinking, and real-world text-processing concepts commonly used in search engines, IDEs, and autocorrect systems.

---

## Features

- Loads a dictionary of words from a file
- Detects whether a word is **correctly spelled**
- Computes similarity using **Levenshtein Distance**
- Suggests the **closest matching words**
- User-defined limit for number of suggestions
- Efficient C++ implementation
- Modular design (dictionary, distance logic, main driver)

---

## Project Structure

```text
TypoFixer-Engine/
│
├── data/
│   └── dictionary.txt              # Word list (dictionary)
│
├── src/
│   ├── dictionary.cpp              # Dictionary loading & lookup logic
│   ├── Levenshtein_distance.cpp    # Edit distance algorithm implementation
│   └── main.cpp                    # Program entry point
│
├── README.md                       # Project documentation
└── .gitignore                      # Ignored system files
```

---

## Algorithm Used

The core algorithm used in this project is the **Levenshtein Distance** algorithm, which calculates the minimum number of single-character edits (insertions, deletions, substitutions) required to change one word into another. This metric helps determine how similar two words are, allowing the engine to suggest the closest valid alternatives for misspelled words.

example:
- Input: "exampel"
- Suggested Correction: "example" (Distance: 1)

this algorithm is widely used in spell-checkers, search engines, and text processing applications to improve user experience by providing accurate suggestions for misspelled words.

---

## How it Works

1. **Load Dictionary**: The program reads a list of valid words from a text file into memory.
2. **User Input**: The user is prompted to enter a word to check.
3. **Check Spelling**: The program checks if the word exists in the dictionary.
4. **Compute Distances**: If the word is misspelled, the program computes the Levenshtein distance between the input word and each word in the dictionary.
5. **Suggest Corrections**: The program sorts the candidate words based on their distance to the input word and suggests the closest matches.

---

## How to Run

1. **Clone the Repository**:
   ```bash
   git clone
   cd TypoFixer-Engine
    ```
2. **Compile the Code**:
   ```bash
   g++ src/*.cpp -o TypoFixerEngine
   ```
3. **Run the Program**:
   ```bash
   ./TypoFixerEngine
   ```
4. **Enter a Word**: Follow the prompt to enter a word and see suggestions if it's misspelled.

---

## Example Usage

```
$ ./TypoFixerEngine
Dictionary is Loaded with 5000 words.
Enter a word to check: bottl
bottl is misspelled.
enter the limit for suggestions: 5
Did you mean:
1. bottle
2. battle
3. boat
4. boil
5. bolt
```

## Time & Space Complexity

### Levenshtein Distance

- **Time Complexity:** `O(n × m)` per comparison  
- **Space Complexity:** `O(n × m)`

Where:
- `n` = length of the input word  
- `m` = length of the dictionary word  

---

### Overall Suggestion Search

- **Time Complexity:** `O(D × L²)`

Where:
- `D` = number of words in the dictionary  
- `L` = average length of a word  

---

*Created by **Rudra Sanandiya**. Licensed under MIT.*