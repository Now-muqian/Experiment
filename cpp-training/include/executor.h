#ifndef EXECUTOR_H
#define EXECUTOR_H

#include<cstdint>
#include<string>
struct  Pose
{
    int32_t x;
    int32_t y;
    char heading;
};



class Executor
{
    public:
    Executor(void)=default;
    virtual ~Executor(void ) = default;

    public:
    virtual void Execute(const std::string& commands)=0;
    virtual void ExecuteOnce(char& command)=0;
    virtual Pose GetStatus() const=0;


    private:
;
    virtual void TurnLeft()=0;
    virtual void TurnRight()=0;
    virtual void Move()=0;
};

#endif