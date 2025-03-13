#pragma once
#include <iostream>

class Address {
    private:
        u_int32_t Tag;
        u_int32_t Index;
        u_int32_t Offset;
    public:
    
    Address();

    void Update(u_int32_t tag, u_int32_t index, u_int32_t offset); 
    u_int32_t GetTag() const;
    u_int32_t GetIndex() const;    
};