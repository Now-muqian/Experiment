#include"executormpl.hpp"
#include"Command.hpp"
#include"unordered_map"
#include<iostream>
#include<memory>

    Executormpl::Executormpl():poseHandler(){}
    
    Executormpl::Executormpl(const Pose& pose,Cartype type):poseHandler(pose,type){}
    Pose Executormpl::Query()const
    {
        return poseHandler.Query();
    }

    void Executormpl::Execute(const std::string& commands)
   {
     const std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap {
        {'M', MoveCommand()},
        {'L', TurnLeftCommand()},
        {'R', TurnRightCommand()},
        {'F', FastCommand()},
        {'B',BackCommand()}
    };

    for(const auto cmd:commands)
    {
        const auto it=cmderMap.find(cmd);
        if(it!=cmderMap.end())
        {
            it->second(poseHandler);
        }
    }
   }



    