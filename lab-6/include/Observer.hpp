#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>
#include <iostream>
#include <fstream>

class Observer {
public:
    virtual void update(const std::string& event) = 0;
    virtual ~Observer() = default;
};

class ConsoleObserver : public Observer {
public:
    void update(const std::string& event) override;
};

class FileObserver : public Observer {
public:
    FileObserver(const std::string& filename);
    ~FileObserver();

    void update(const std::string& event) override;

private:
    std::ofstream logFile_;
};

#endif