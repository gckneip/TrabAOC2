#include "../address.hpp"
#include <cstdint>

Address::Address(){};

uint32_t Address::GetTag() const { return Tag; };
uint32_t Address::GetIndex() const { return Index; };
void Address::Update(uint32_t tag, uint32_t index, uint32_t offset){
    Tag = tag;
    Index = index;
    Offset = offset;
}
