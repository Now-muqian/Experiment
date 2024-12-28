#include"executormpl.hpp"
#include"Command.hpp"
#include<iostream>
#include<memory>

    Executormpl::Executormpl():poseHandler(){}
    
    Executormpl::Executormpl(const Pose& pose):poseHandler(pose){}
    Pose Executormpl::Query()const
    {
        return poseHandler.Query();
    }
    void Executormpl::ExecuteOnce(char& command)
    {
        
        std::unique_ptr<ICommand> cmder;
        switch (command)
        {
        case 'M':
        {
       cmder=std::make_unique<MoveCommand>();
         break;
        }

        case 'L':
        {
       cmder=std::make_unique<TurnLeftCommand>();
        break; 
        }
        case 'R':
        {
        cmder=std::make_unique<TurnRightCommand>();
        break;
        }
        case 'F':
        {
        cmder=std::make_unique<FastCommand>();
        break;
        }
        default:
            break;
       }
       if(cmder)
       {
        cmder->DoOperate(poseHandler);
       }
        return;
    }
    void Executormpl::Execute(const std::string& commands)
    {
        for(char command : commands)
        {
            ExecuteOnce(command);
        }

        return;
    }

    