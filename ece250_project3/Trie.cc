#include "Trie.h"

Trie::Trie() : size(0), root{new Node()} {}

Trie::~Trie() {
  // Delete all nodes (including the root)
  delete_node(root);
  size = 0;
}

Trie::RetStat Trie::Insert(const std::string& word) {
  // check if the argument is valid
  try {
    if(!check_args(word))
      throw illegal_argument();
  } catch (...) {
    std::cout << "illegal argument\n";
    return RetStat::ILLEGAL;
  }
  // assert(word is legal)
  Node* temp = root;
  for(const char c : word) {
    // get the index in the children
    int i = static_cast<int>(c - 'A');
    if(temp->getChildren()[i] == nullptr)
      temp->getChildren()[i] = new Node();
    temp = temp->getChildren()[i];
  }
  // check if the word has already been added
  if(temp->EndofWord())
    return RetStat::FAILED;
  // otherwise, mark this node as end of word
  temp->SetEndofWord(true);
  ++size;
  return RetStat::SUCCESS;
}

int Trie::CountPrefix(const std::string& prefix) const {
  // check if the argument is valid
  try {
    if(!check_args(prefix))
      throw illegal_argument();
  } catch (...) {
    std::cout << "illegal argument\n";
    return -1;
  }
  // assert(prefix is legal)
  Node* temp = root;
  for(const char c : prefix) {
    int i = static_cast<int>(c - 'A');
    if(temp->getChildren()[i] == nullptr)
      return 0;
    temp = temp->getChildren()[i];
  }
  // start counting the number
  return count_prefix(temp);
}

Trie::RetStat Trie::Erase(const std::string& word) {
  // check if the argument is valid
  try {
    if(!check_args(word) || word.size() == 0)
      throw illegal_argument();
  } catch (...) {
    std::cout << "illegal argument\n";
    return RetStat::ILLEGAL;
  }
  // assert(word is legal)
  // check if the word is end of word
  Node* temp = root;
  for(const char c : word) {
    int i = static_cast<int>(c - 'A');
    Node* next = temp->getChildren()[i];
    if(next == nullptr)
      return RetStat::FAILED;
    temp = next;
  }
  if(!temp->EndofWord())
    return RetStat::FAILED;
  // assert(word is present and found in trie)
  // CANNOT delete directly from the node
  int i = static_cast<int>(word[0] - 'A');
  Node*& first = root->getChildren()[i];
  first = delete_word(first, word, 1);
  --size;
  return RetStat::SUCCESS;
}

void Trie::PrintTrie() const {
  if(size == 0)
    return;
  std::string path;
  for(int i = 0; i < N; i++) {
    if(root->getChildren()[i] != nullptr) {
      path.push_back(static_cast<char>(i + 'A'));
      backtracking(root->getChildren()[i], path);
      path.pop_back();
    }
  }
  std::cout << '\n';
}

bool Trie::SpellCheck(const std::string& word) const {
  // if no match on the first letter, then output a new line
  int i = static_cast<int>(word[0] - 'A');
  if(root->getChildren()[i] == nullptr) {
    std::cout << '\n';
    return false;
  }
  // go through each character and check each
  Node* temp = root;
  std::string path;
  bool isCorrect = true;
  for(const char c : word) {
    int idx = static_cast<int>(c - 'A');
    if(temp->getChildren()[idx] == nullptr) {
      isCorrect = false;
      break;
    } else {
      path.push_back(c);
      temp = temp->getChildren()[idx];
    }
  }
  if(temp->EndofWord() && isCorrect) {
    return true;
  } else {
    backtracking(temp, path);
    std::cout << '\n';
  }
  return false;
}

void Trie::clear() {
  // delete all nodes except for the root node
  for(int i = 0; i < N; i++) {
    if(root->getChildren()[i] != nullptr) {
      delete_node(root->getChildren()[i]);
      root->getChildren()[i] = nullptr;
    }
  }
  // update size to 0
  size = 0;
}

void Trie::PrintSize() const {
  std::cout << "number of words is " << size << '\n';
}

bool Trie::isEmpty() const {
  return (size == 0);
}

void Trie::delete_node(Node* node) {
  for(int i = 0; i < N; i++) {
    if(node->getChildren()[i] != nullptr)
      delete_node(node->getChildren()[i]);
  }
  delete node;
}

bool Trie::check_args(const std::string& arg) {
  for(const char c : arg) {
    if(c < 'A' || c > 'Z')
      return false;
  }
  return true;
}

int Trie::count_prefix(Node* node) {
  int sum = 0;
  if(node->EndofWord())
    ++sum;
  for(int i = 0; i < N; i++) {
    if(node->getChildren()[i] != nullptr)
      sum += count_prefix(node->getChildren()[i]);
  }
  return sum;
}

void Trie::backtracking(Node* node, std::string& path) {
  if(node == nullptr)
    return;
  if(node->EndofWord())
    std::cout << path << ' ';
  for(int i = 0; i < N; i++) {
    path.push_back(static_cast<char>(i + 'A'));
    backtracking(node->getChildren()[i], path);
    path.pop_back();
  }
}

Node* Trie::delete_word(Node* node, const std::string& word, int idx) {
  if(node == nullptr)
    return nullptr;
  if(idx == word.size()) {
    if(node->EndofWord())
      node->SetEndofWord(false);
    // if the node has no other children, delete it
    if(count_children(node) == 0) {
      delete node;
      node = nullptr;
    }
    return node;
  }
  // recursively delete the character
  int i = static_cast<int>(word[idx] - 'A');
  Node*& temp = node->getChildren()[i];
  temp = delete_word(temp, word, idx + 1);
  // if the node has no other children, delete it
  if(count_children(node) == 0 && !node->EndofWord()) {
    delete node;
    node = nullptr;
  }
  return node;
}

int Trie::count_children(Node* node) {
  int count = 0;
  for(int i = 0; i < N; i++) {
    if(node->getChildren()[i] != nullptr)
      count++;
  }
  return count;
}