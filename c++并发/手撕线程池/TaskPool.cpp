#include"TaskPool.h"
TaskPool::TaskPool():m_bRunning(false)
{

}
TaskPool::~TaskPool()
{
    removeAllTasks();
}
void TaskPool::init(int threadNum)
{
    if (threadNum<5)
    {
        /* code */
        threadNum = 5;
    }
    m_bRunning = true;
    for (int i = 0; i < threadNum; ++i)
    {
        /* code */
        std::shared_ptr<std::thread> spThread;
        spThread.reset(new std::thread(std::bind(&TaskPool::threadFunc)));
        m_threads.push_back(spThread);
    }   
}
void TaskPool::threadFunc()
{
    
}