#ifndef EXECUTORMPL_H
#define EXECUTORMPL_H

#include"executor.h"


class Executormpl:public Executor
{
    public:
    Executormpl();
    Executormpl(const Pose& pose);
    ~Executormpl()=default;

    public:
    void Execute(const std::string& commands) override;
    void ExecuteOnce(char& command)override;
    Pose GetStatus() const override;


     private:
     Pose pose;
     char turnSequence[8]={'S',0,'W','S',0,'E','N','W'};
     void TurnLeft() override;
     void TurnRight() override;
     void Move() override;
};

#endif