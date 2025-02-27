#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class TrieNode {
    public:
        bool isWord;
        char letter;
        vector<TrieNode*> children;

        TrieNode(char letter) {
            this -> isWord = false;
            this -> letter = letter;
            this -> children = vector<TrieNode*>(26);
        }
};

unordered_map<int, char> alphabet_forward({{0, 'a'}, {1, 'b'}, {2, 'c'},
                                  {3, 'd'}, {4, 'e'},{5, 'f'},{6, 'g'},{7, 'h'},{8, 'i'},{9, 'j'},{10, 'k'},{11, 'l'},{12, 'm'},{13, 'n'},{14, 'o'},{15, 'p'},{16, 'q'},{17, 'r'},{18, 's'},{19, 't'},{20, 'u'},{21, 'v'},{22, 'w'},{23, 'x'},{24, 'y'},{25, 'z'},});

unordered_map<char, int> alphabet_backward;

int minimumLengthEncodingMap(vector<string> &words) {
        unordered_set<string> nodupwords(words.begin(), words.end());
        unordered_map<string, string> prefixes;

        for (string word : nodupwords) {
          for (int i = 1; i < word.size(); i++) {
                string suffix = word.substr(i);
                if (prefixes.find(suffix) == prefixes.end()) {
                    prefixes.emplace(suffix, word);
                } else {
                    unordered_map<string, string>::iterator it = prefixes.find(suffix);
                    if (it->second.size() < word.size()) {
                        prefixes.at(it -> first) = word;
                    } else {
                         continue;
                    }
                }
            }
        }

        int answer = 0;
        for (string word : nodupwords) {
          if (prefixes.find(word) != prefixes.end()) {
                continue;
          } else {
              answer += word.size() + 1;
          }
        }

        return answer;
}

bool isLeaf(TrieNode node) {
  for (int i = 0; i < node.children.size(); i++) {
    if (node.children[i] != NULL) {
          return false;
      }
    }
  return true; 
}

void getWordLengths(TrieNode *node, int level, vector<int> &word_lengths) {
  if (isLeaf(*node)) {
        word_lengths.push_back(level);
  } else {
    for (int i = 0; i < node->children.size(); i++) {
      if (node->children[i] != NULL) {
            getWordLengths(node -> children[i], level + 1, word_lengths);
        }
      }
  }
}

int minimumLengthEncodingTrie(vector<string>& words) {
    TrieNode root = TrieNode('-');

    // Loop through the array of words
    // Loop through each word in backwards order and insert them into the Trie
    for (string word : words) {
        TrieNode* trie_iterator = &root;
      for (int char_index = word.size() - 1; char_index > -1; char_index--) {
          // If found, set the iterator to that child
          if (trie_iterator -> children.at(alphabet_backward.find(word[char_index]) -> second) != NULL) {
            trie_iterator = trie_iterator -> children.at(alphabet_backward.find(word[char_index]) -> second);
          } 
          // Insert the char as a new node since it doesn't exist for that node
          else {
            TrieNode* inserted_node = new TrieNode(word[char_index]);
            trie_iterator -> children.at(alphabet_backward.find(word[char_index]) -> second) = inserted_node;
            trie_iterator = inserted_node;
          }
        }
    }

    // From all the leaves, gather the unique path lengths and sum them up + 1 for the hash
    vector<int> word_lengths;
    int result = 0;
    
    getWordLengths(&root, 0, word_lengths);

    for (int word_length : word_lengths) {
        result += word_length + 1;
    }

    return result;
}

int main() {

    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    for (auto rit = alphabet_forward.begin();
         rit != alphabet_forward.end(); rit++) {
        alphabet_backward.emplace(rit->second, rit->first);
    }
    
    string raw_input;
    vector<string> words;
    
    while(getline(cin, raw_input, ' ')){
        words.push_back(raw_input);
    }

    string last_word = words.at(words.size() - 1);
    words.at(words.size() - 1) = last_word.erase(last_word.size() - 1);
    
    cout << "MAP SOLUTION: " << minimumLengthEncodingMap(words) << endl;
    cout << "TRIE SOLUTION: " << minimumLengthEncodingTrie(words) << endl;

    return 0;
}
