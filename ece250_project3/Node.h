#ifndef NODE_H
#define NODE_H

#include <iostream>

// the number of children each node should have
constexpr int N = 26;

// class for each node in trie
class Node {
 public:
  // initialize variables
  // --------------------
  Node();

  // Getter & Setter for End of word
  // -------------------------------
  bool EndofWord() const;
  void SetEndofWord(const bool status);

  // Getter & Setter for children
  // ----------------------------
  Node** getChildren();

 private:
  bool isEndofWord;   // tracks if the char is the end of a word
  Node* Children[N];  // the array of children
};

#endif