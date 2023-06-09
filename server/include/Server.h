#ifndef _SERVER_H_
#define _SERVER_H_

#include "EventLoop.h"
#include <memory>
#include <map>
#include <vector>

class Socket;
class Acceptor;
class Account;
class Connection;
class Mysql;
class Server{
private:
    EventLoop* MainReactor;
    Acceptor* acceptor;
    std::map<int, Connection*> connections;
    std::vector<EventLoop*> SubReators;
    ThreadPool* thread_pool;
    Mysql* mysql;
    std::function<void(Connection*)> OnConnectionCallback;
public:
    Server(EventLoop*);
    ~Server();

    void handleReadEvent(int);
    void NewConnection(std::shared_ptr<Socket>);
    void DeleteConnection(std::shared_ptr<Socket>);

    bool Insert(const Account*);
    bool Delete(const Account*);
    bool Modify(const Account*);
    ssize_t Check(const Account*);
    bool FdSet(const Account*, int);

    std::vector<std::string> LookList(const Account*);
    std::vector<int> GetOnlFd();
    bool Find(const char*);
    void AddShip(Account*, const char*);
    int FindFd(const char*);
};

#endif