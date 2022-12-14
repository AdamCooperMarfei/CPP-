#include<iostream>
#include<thread>
#include<condition_variable>
std::mutex mtx;
std::condition_variable cv;
int ready = 0;
void PringString1()
{
    std::unique_lock<std::mutex> lk(mtx);
    int cnt =0;
    while (cnt<10)
    {
        /* code */
        while (ready != 0)
        {
            /* code */
            cv.wait(lk);
        }
        std::cout<<std::this_thread::get_id()<<" : "<<"A"<<std::endl;
        ready = 1;
        cnt++;
        cv.notify_all();  
    }
}
void PrintString2()
{
   std::unique_lock<std::mutex> lk(mtx);
   int cnt = 0;
   while (cnt<10)
   {
    /* code */
    while (ready!=1)
    {
        /* code */
        cv.wait(lk);
    }
    std::cout<<std::this_thread::get_id()<<" : "<<"B"<<std::endl;
    ready = 2;
    cnt++;
    cv.notify_all();
   }
}
void PrintString3()
{
    std::unique_lock<std::mutex> lk(mtx);
    int cnt = 0;
    while (cnt<10)
    {
        /* code */
        while (ready!=2)
    {
        /* code */
        cv.wait(lk);
    }
    std::cout<<std::this_thread::get_id()<<" : "<<"C"<<std::endl;
    ready = 0;
    cnt++;
    cv.notify_all();
    }
}
int main()
{
    std::thread t1(PringString1);
    std::thread t2(PrintString2);
    std::thread t3(PrintString3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}