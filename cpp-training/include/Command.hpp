#pragma once

#include"PoseHandler.hpp"

    class ICommand
     {
      public:
      
      virtual ~ICommand()=default;
      virtual void DoOperate(PoseHandler& executor)const =0;
    
     };
    class MoveCommand:public ICommand
     {
     public:
     void DoOperate(PoseHandler& executor)const override
     {
      if(executor.IsFast())
      {
         executor.Move();
      }
         executor.Move();
        
     }
     };
    class TurnLeftCommand:public ICommand
     {
     public:
     void DoOperate(PoseHandler& executor)const override
     {
      if(executor.IsFast())
      {
         executor.Move();
      }
         executor.TurnLeft();
        
     }
     };
    class TurnRightCommand:public ICommand
     {
     public:
     void DoOperate(PoseHandler& executor)const override
     {
      if(executor.IsFast())
      {
         executor.Move();
      }
         executor.TurnRight();
        
     }
     };
    class FastCommand:public ICommand
     {
      public:
      void DoOperate(PoseHandler& executor)const override
      {
         executor.Fast();
      }
     };

