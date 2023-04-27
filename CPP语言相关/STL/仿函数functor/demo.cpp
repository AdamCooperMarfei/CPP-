#include<iostream>
void foo(int x){
    std::cout<<"foo("<<x<<")\n";
}
int main(){
    //使用函数指针调用foo
    void (*fp)(int) = foo;
    fp(1);
    struct S
    {
        /* data */
        void operator()(int x) const{
            std::cout << "S::operator(" << x << ")\n";
        }
    }s;
    //calls s.operator
    s.operator()(3);
    s(2);
    auto lam = [](int x){
        std::cout<<"lambda("<<x<<")\n";
    };
    lam(4);
    lam.operator()(5);
}