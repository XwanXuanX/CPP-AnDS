#include "Trie.h"

#include <iostream>
#include <fstream>

int main() {
  Trie trie;
  std::string cmd;
  std::string addWord;
  while(std::cin >> cmd)
  {
    if(cmd == "load") 
    {
      std::ifstream fin("corpus.txt");
      while(fin >> addWord) 
      {
        trie.Insert(addWord);
      }
      std::cout << "success\n";
    } 
    else if(cmd == "i") 
    {
      std::cin >> addWord;
      Trie::RetStat stat = trie.Insert(addWord);
      if(stat == Trie::RetStat::FAILED)
        std::cout << "failure\n";
      else if(stat == Trie::RetStat::SUCCESS)
        std::cout << "success\n";
    } 
    else if(cmd == "c") 
    {
      std::cin >> addWord;
      int count = trie.CountPrefix(addWord);
      if(count == 0)
        std::cout << "not found\n";
      else if(count == -1) { /* DO NOTHING! */ }
      else
        std::cout << "count is " << count << '\n';
    } 
    else if(cmd == "e") 
    {
      std::cin >> addWord;
      Trie::RetStat stat = trie.Erase(addWord);
      if(stat == Trie::RetStat::FAILED)
        std::cout << "failure\n";
      else if(stat == Trie::RetStat::SUCCESS)
        std::cout << "success\n";
    } 
    else if(cmd == "p") 
    {
      trie.PrintTrie();
    } 
    else if(cmd == "spellcheck") 
    {
      std::cin >> addWord;
      if(trie.SpellCheck(addWord))
        std::cout << "correct\n";
    } 
    else if(cmd == "empty") 
    {
      if(trie.isEmpty())
        std::cout << "empty 1\n";
      else
        std::cout << "empty 0\n";
    }
    else if(cmd == "clear") 
    {
      trie.clear();
      std::cout << "success\n";
    }
    else if(cmd == "size") 
    {
      trie.PrintSize();
    }
    else if(cmd == "exit") 
    {
      return 0;
    }
  }
}