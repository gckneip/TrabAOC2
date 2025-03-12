#pragma once 

class Block {
    private:
        int Tag;        bool Valid;

    public:
        Block();  

        void Validate();
        bool IsValid() const;
        void SetTag(int tag);
        bool CompareTag(int tag) const;
};
