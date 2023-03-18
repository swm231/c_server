#ifndef _SERVER_H_
#define _SERVER_H_

#include "EventLoop.h"

class Socket;
class Server{
private:
    EventLoop* loop;
public:
    Server(EventLoop*);
    ~Server();

    void handleReadEvent(int);
    void NewConnection(Socket*);
};

#endif