/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.
Implement the WordDictionary class:
WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.
 
Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]
Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 
Constraints:
1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search.
*/

//Time Complexity : O(N * word.size()), all words can be of the same size thus will need a traversal of vector once. (Someone comment: It is not O(N), you should also account for words length. You should also account for a number of queries.)
//Space Complexity : O(N), N number of words are stored.
class WordDictionary {
    unordered_map<int, vector<string>> words; // unordered_map to store index as the size of word and vector of string to store words of same sizes
public:
    WordDictionary() {}
    
    void addWord(string word) {
         words[word.size()].push_back(word); //To insert a word we just need to push the word at words[word.size()].push_back(word)
    }
    
    bool search(string word) {   //For search operation we just need to search at words[word.size()]
        
          for (auto &&s : words[word.size()])
               if (isEqual(s, word))
                    return true;
          return false;
    }
  
  //As we have a wild operator. which can be equal to any alphabet thus we need to create a function bool isEqual(string word1, string word2) so that it can ignore the particular character while comparing with other characters 
  //Eg:- "a . c" == "a b c' or vice versa "a b c" == "a . c"
    bool isEqual(string word1, string word2)  
     {
          for (int i = 0; i < word1.size(); i++)
          {
               if (word2[i] == '.')
                    continue;
               if (word1[i] != word2[i])
                    return false;
          }
          return true;
     }
};
