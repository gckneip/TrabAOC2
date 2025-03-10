#include "block.hpp" 

Block::Block() : Tag(0), Counter(0), Valid(false) {}

void Block::Validate() { Valid = true; }

bool Block::IsValid() const { return Valid; }

void Block::SetTag(int tag) { Tag = tag; }

void Block::AddCounter() { Counter++; }

void Block::ResetCounter() { Counter = 0; }

bool Block::CompareTag(int tag) const { return Tag == tag; }
