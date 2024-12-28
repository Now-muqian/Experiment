#pragma once
#include <functional>
#include"PoseHandler.hpp"


    class MoveCommand final 
     {
     public:
     void operator()(PoseHandler& poseHandler) noexcept 
     {
      Cartype type=poseHandler.QueryType();
      switch(type)
      {
         case Car:
         {
         if(poseHandler.IsBack())
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
        poseHandler.Backward();
      }
      else
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.Move();
         }
         break;
      }
      case SportsCar:
      {
          if(poseHandler.IsBack())
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
            poseHandler.Backward();
         }
        poseHandler.Backward();
        poseHandler.Backward();
      }
      else
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
            poseHandler.Move();
         }
         poseHandler.Move();
         poseHandler.Move();
         }
         break;
      }
      case Bus:
        {
          if(poseHandler.IsBack())
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
        poseHandler.Backward();
      }
      else
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.Move();
         }
         break;
      }
      default :break;
      } 
     };
     };
  
    class TurnLeftCommand final//:public ICommand
     {
     public:
     void operator()(PoseHandler& poseHandler) noexcept 
     {
       Cartype type=poseHandler.QueryType();
      switch(type)
      {
         case Car:
         {
         if(poseHandler.IsBack())
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
         poseHandler.TurnRight();
      }
      else
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.TurnLeft();
      } 
         break;
      }
      case SportsCar:
      {
          if(poseHandler.IsBack())
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
         poseHandler.TurnRight();
         poseHandler.Backward();
      }
      else
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.TurnLeft();
         poseHandler.Move();
         }
         break;
      }
      case Bus:
        {
          if(poseHandler.IsBack())
      {
         poseHandler.Backward();
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
        poseHandler.TurnRight();
      }
      else
      {
         poseHandler.Move();
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.TurnLeft();
         }
         break;
      }
      default :break;
      } 
      
        
        
     };
     };
    class TurnRightCommand final
    {
     public:
     void operator()(PoseHandler& poseHandler) noexcept 
     {
       Cartype type=poseHandler.QueryType();
      switch(type)
      {
         case Car:
         {
         if(poseHandler.IsBack())
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
         poseHandler.TurnLeft();
      }
      else
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.TurnRight();
      } 
         break;
      }
      case SportsCar:
      {
          if(poseHandler.IsBack())
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
         poseHandler.TurnLeft();
         poseHandler.Backward();
      }
      else
      {
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.TurnRight();
         poseHandler.Move();
         }
         break;
      }
      case Bus:
        {
          if(poseHandler.IsBack())
      {
         poseHandler.Backward();
         if(poseHandler.IsFast())
         {
            poseHandler.Backward();
         }
        poseHandler.TurnLeft();
      }
      else
      {
         poseHandler.Move();
         if(poseHandler.IsFast())
         {
            poseHandler.Move();
         }
         poseHandler.TurnRight();
         }
         break;
      }
      default :break;
      } 
     };
     };
    class FastCommand final
     {
      public:
      void operator()(PoseHandler& poseHandler) noexcept 
     {
         poseHandler.Fast();
      };
     };
    class BackCommand final
     {
      public:
      void operator()(PoseHandler& poseHandler) noexcept 
     {
         poseHandler.Back();
      };
     };
