#ifndef EXECUTOR_H
#define EXECUTOR_H

#include<cstdint>
#include<string>

class Executor
{
    public:
    Executor();
    Executor(int x,int y,char heading);

    void Execute(char command);
    void ExecuteCommands(std::string commands);
    std::string GetStatus() const;


    private:
    int32_t x,y;
    char heading;
    char turnSequence[8]={'S','0','W','S','0','E','N','W'};
    int fast=0;
    void TurnLeft();
    void TurnRight();
    void Move();


};

#endif
