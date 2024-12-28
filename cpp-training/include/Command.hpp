#pragma once
#include <functional>
#include"PoseHandler.hpp"


    class MoveCommand final 
     {
     public:
     void operator()(PoseHandler& poseHandler) noexcept 
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
        
     };
     };
     class BackwardCommand final
     {
      public:
      void operator()(PoseHandler& poseHandler) noexcept 
     {
         poseHandler.Backward();
      };
     };
    class TurnLeftCommand final//:public ICommand
     {
     public:
     void operator()(PoseHandler& poseHandler) noexcept 
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
        
        
     };
     };
    class TurnRightCommand final
    {
     public:
     void operator()(PoseHandler& poseHandler) noexcept 
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
