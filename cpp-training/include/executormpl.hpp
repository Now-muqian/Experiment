#pragma once

#include"executor.hpp"
#include"PoseHandler.hpp"

class Executormpl final :public Executor 
{
    public:
    Executormpl();
    Executormpl(const Pose& pose);
    ~Executormpl()=default;

    public:
    void Execute(const std::string& commands) override;

   Pose Query()const override;
   private:
   PoseHandler poseHandler;

      
 

};
