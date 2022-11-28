#include<iostream>
class HasPtrMem
{
private:
    /* data */
    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;

public:
    HasPtrMem():d(new int(0))
    {
        std::cout<<"construct: "<<++n_cstr<<std::endl;
    }
    HasPtrMem(const HasPtrMem &h):d(new int(*h.d))
    {
        std::cout<<"copy construct"<<++n_cptr<<std::endl;
    }
    ~HasPtrMem();
};

HasPtrMem::~HasPtrMem()
{
    std::cout<<"destruct: "<<++n_dstr<<std::endl;
}

int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;

HasPtrMem GetTemp()
{
    return HasPtrMem();
}

int main()
{
    HasPtrMem a = GetTemp();
}
