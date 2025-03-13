#include "../block.hpp" 
#include <iostream>

Block::Block() : Tag(0), Valid(false) {}

void Block::Validate() { Valid = true; }

bool Block::IsValid() const { return Valid; }

void Block::SetTag(u_int32_t tag) { Tag = tag; }

bool Block::CompareTag(u_int32_t tag) const { return Tag == tag; }
