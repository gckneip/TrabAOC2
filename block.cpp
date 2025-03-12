#include "block.hpp" 

Block::Block() : Tag(0), Valid(false) {}

void Block::Validate() { Valid = true; }

bool Block::IsValid() const { return Valid; }

void Block::SetTag(int tag) { Tag = tag; }



bool Block::CompareTag(int tag) const { return Tag == tag; }
