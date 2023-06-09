#ifndef _EVENTLOOP_H_
#define _EVENTLOOP_H_

#include "Epoll.h"
#include "ThreadPool.h"
#include <memory>

class Channel;
class Epoll;
class EventLoop{
private:
    Epoll* ep;
    bool quit;
    //ThreadPool* pool;
public:
    EventLoop();
    ~EventLoop();
    void loop();
    void updataChannel(Channel*);
    void deleteChannel(Channel*);
    void AddTask(std::function<void()>);
};

#endif