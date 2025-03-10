#include "address.hpp"

Address::Address(int tag, int index, int offset): Tag(tag), Index(index), Offset(offset){}

int Address::GetTag() const { return Tag; };
int Address::GetIndex() const { return Index; };
//int Address::GetOffset() const { return Offset; };