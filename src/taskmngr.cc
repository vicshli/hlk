#include "taskmngr.h"

namespace tasks
{
const unsigned int TaskManager::ROOT_ = 0;
unsigned int TaskManager::taskctr_    = 1;

TaskManager::TaskManager() {}

tid_t TaskManager::add_task(std::string taskname) { return add_task(taskname, ROOT_); }

tid_t TaskManager::add_task(std::string taskname, tid_t ptid)
{
    if (!find(ptid)) return -1;
    tid_t tid = taskctr_++;
    tasktable_.insert(TDE_t(tid, task_t(taskname, tid, ptid)));
    return tid;
}

bool TaskManager::find(tid_t tid) { return tid < taskctr_; }

std::ostream& operator<<(std::ostream &os, const TaskManager &tmg)
{
    std::cout << "-------------------- Tasks --------------------\n";
    std::cout << "TID \tPTID \tNAME";
    for (auto const &task : tmg.tasktable_)
    {
        std::cout << "\n" 
                  << task.second.tid << "\t"
                  << task.second.ptid << "\t"
                  << task.second.name;
    }
    return os;
}


} // namespace tasks