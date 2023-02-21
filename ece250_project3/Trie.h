#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include "Node.h"

// Illegal-argument class
class illegal_argument : public std::exception {
 public:
  inline const char* what() {
    return "Illegal argument detected!\n";
  }
};

// class for the Trie
class Trie {
 public:
  // public enum for return status
  // -----------------------------
  enum class RetStat : char {
    SUCCESS,  // when successfully executed
    FAILED,   // when failed
    ILLEGAL   // when argument is invalid
  };

  // initialize variables
  // --------------------
  Trie();

  // Deallocate all nodes
  // --------------------
  ~Trie();

  // Insert a new word into the trie
  // -------------------------------
  RetStat Insert(const std::string& word);

  // Output the number of words with prefix
  // --------------------------------------
  int CountPrefix(const std::string& prefix) const;

  // Erase the word in the trie
  // --------------------------
  RetStat Erase(const std::string& word);

  // Prints all the words in trie 
  // ----------------------------
  void PrintTrie() const;

  // spell checks the word and offer suggestions
  // -------------------------------------------
  bool SpellCheck(const std::string& word) const;
  
  // Delete all words from the trie
  // ------------------------------
  void clear();

  // prints the number of words in the trie
  // --------------------------------------
  void PrintSize() const;

  // check if the trie is empty
  // --------------------------
  bool isEmpty() const;

private:
  // helper function: recursively delete nodes in the tree
  // -----------------------------------------------------
  void delete_node(Node* node);

  // helper function to check validity of arguments
  // ----------------------------------------------
  static bool check_args(const std::string& arg);

  // helper function to count the number of words
  // --------------------------------------------
  static int count_prefix(Node* node);

  // helper function to print the trie
  // ---------------------------------
  static void backtracking(Node* node, std::string& path);

  // helper function to delete a word from the trie
  // ----------------------------------------------
  Node* delete_word(Node* node, const std::string& word, int idx);

  // helper function to count the number of children of a node
  // ---------------------------------------------------------
  static int count_children(Node* node);

 private:
  std::uint32_t size; // the number of words in the trie
  Node* root;         // the root of the trie
};

#endif