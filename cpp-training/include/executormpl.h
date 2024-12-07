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
      int isFast=0;
     Pose pose;
     char turnSequence[8]={'S',0,'W','S',0,'E','N','W'};
      class ICommand
     {
      public:
      
      virtual ~ICommand()=default;
      virtual void DoOperate(Executormpl& executor)const =0;
    
     };
    class MoveCommand:public ICommand
     {
     public:
     void DoOperate(Executormpl& executor)const override
     {
      if(executor.isFast==0)
        executor.Move();
        else
        {
         executor.Move();
         executor.Move();
        }
     }
     };
    class TurnLeftCommand:public ICommand
     {
     public:
     void DoOperate(Executormpl& executor)const override
     {
      if(executor.isFast==0)
        executor.TurnLeft();
        else
        {
         executor.Move();
         executor.TurnLeft();
        }
     }
     };
    class TurnRightCommand:public ICommand
     {
     public:
     void DoOperate(Executormpl& executor)const override
     {
      if(executor.isFast==0)
        executor.TurnRight();
        else
        {
         executor.Move();
         executor.TurnRight();
        }
     }
     };
     class FastCommand:public ICommand
     {
      public:
      void DoOperate(Executormpl& executor)const override
      {
         executor.Fast();
      }
     };
 
     void TurnLeft() ;
     void TurnRight() ;
     void Move() ;
     void Fast();
};

#endif