#include "../address.hpp"
#include <iostream>

Address::Address(){};

u_int32_t Address::GetTag() const { return Tag; };
u_int32_t Address::GetIndex() const { return Index; };
void Address::Update(u_int32_t tag, u_int32_t index, u_int32_t offset){
    Tag = tag;
    Index = index;
    Offset = offset;
}
