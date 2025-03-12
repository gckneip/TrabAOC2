#pragma once

class Address {
    private:
        int Tag;
        int Index;
        int Offset;
    public:
    
    Address();

    void Update(int tag, int index, int offset); 
    int GetTag() const;
    int GetIndex() const;    
};