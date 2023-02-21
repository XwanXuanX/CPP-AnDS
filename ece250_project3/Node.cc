#include "Node.h"

Node::Node() : isEndofWord(false) {
  for(Node*& node : Children)
    node = nullptr;
}

bool Node::EndofWord() const {
  return isEndofWord;
}

void Node::SetEndofWord(const bool status) {
  isEndofWord = status;
}

Node** Node::getChildren() {
  return Children;
}