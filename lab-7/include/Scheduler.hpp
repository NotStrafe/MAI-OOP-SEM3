#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <coroutine>
#include <deque>
#include <memory>
#include <functional>
#include "Task.hpp"

class Task;

class Scheduler {
public:
    void schedule(Task&& task);
    void run();

    static Scheduler& instance();

private:
    std::deque<Task> tasks;
};

#endif