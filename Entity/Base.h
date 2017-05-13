#ifndef MANAGER_TASKS_BASE_H
#define MANAGER_TASKS_BASE_H


class Base
{
protected:
    short id;
    Base() : id(readId()){};
private:
    //to increment id
    void renewId(short oldId);
    //returns id from a file
    short readId();
public:
    short getBaseId();

    virtual ~Base();
};


#endif

