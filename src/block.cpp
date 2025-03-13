#include "../block.hpp" 
#include <cstdint>

Block::Block() : Tag(0), Valid(false) {}

void Block::Validate() { Valid = true; }

bool Block::IsValid() const { return Valid; }

void Block::SetTag(uint32_t tag) { Tag = tag; }

bool Block::CompareTag(uint32_t tag) const { return Tag == tag; }
