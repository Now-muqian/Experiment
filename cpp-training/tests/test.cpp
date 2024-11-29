#include <gtest/gtest.h>

#include "executor.h"


TEST(ExecutorTest, return_defalut_status_when_without_init_and_command)
{
    
    auto executor = std::make_unique<Executor>();
    const std::string expectedStatus = "(0,0,N)";
    ASSERT_EQ(expectedStatus, executor->GetStatus()); 
}
TEST(ExecutorTest, return_defalut_status_when_with_init)
{
    
    auto executor = std::make_unique<Executor>(7, 4, 'W');
    const std::string expectedStatus = "(7,4,W)";
    ASSERT_EQ(expectedStatus, executor->GetStatus());
}
//MoveForward Test
TEST(ExecutorTest, MoveForward_when_with_init_and_E_Heading) 
{
    Executor executor(-5,6,'E');
    executor.Execute('M');
    const std::string expectedStatus = "(-4,6,E)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
TEST(ExecutorTest, MoveForward_when_with_init_and_W_Heading) 
{
    Executor executor(7,6,'W');
    executor.Execute('M');
    const std::string expectedStatus = "(6,6,W)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
TEST(ExecutorTest, MoveForward_when_with_init_and_N_Heading) 
{
    Executor executor(-6,5,'N');
    executor.Execute('M');
    const std::string expectedStatus = "(-6,6,N)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
TEST(ExecutorTest, MoveForward_when_with_init_and_S_Heading) 
{
    Executor executor(6,-7,'S');
    executor.Execute('M');
    const std::string expectedStatus = "(6,-8,S)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
//TrunLeft Test
TEST(ExecutorTest, TrunLeft_when_with_init_and_S_Heading) 
{
    Executor executor(4,7,'S');
    executor.Execute('L');
    const std::string expectedStatus = "(4,7,E)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
TEST(ExecutorTest, TrunLeft_when_with_init_and_E_Heading) 
{
    Executor executor(4,7,'E');
    executor.Execute('L');
    const std::string expectedStatus = "(4,7,N)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
TEST(ExecutorTest, TrunLeft_when_with_init_and_N_Heading) 
{
    Executor executor(-4,7,'N');
    executor.Execute('L');
    const std::string expectedStatus = "(-4,7,W)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
TEST(ExecutorTest, TrunLeft_when_with_init_and_W_Heading) 
{
    Executor executor(4,-7,'W');
    executor.Execute('L');
    const std::string expectedStatus = "(4,-7,S)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
//TrunRight Test
TEST(ExecutorTest, TrunRight_when_with_init_and_S_Heading) 
{
    Executor executor(8,6,'S');
    executor.Execute('R');
    const std::string expectedStatus = "(8,6,W)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
TEST(ExecutorTest, TrunRight_when_with_init_and_W_Heading) 
{
    Executor executor(8,6,'W');
    executor.Execute('R');
    const std::string expectedStatus = "(8,6,N)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
 TEST(ExecutorTest, TrunRight_when_with_init_and_N_Heading) 
{
    Executor executor(8,6,'N');
    executor.Execute('R');
    const std::string expectedStatus = "(8,6,E)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
 TEST(ExecutorTest, TrunRight_when_with_init_and_E_Heading) 
{
    Executor executor(8,6,'E');
    executor.Execute('R');
    const std::string expectedStatus = "(8,6,S)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
//ExecuteCommands Test 
  TEST(ExecutorTest, ExecuteCommands_when_without_init_First) 
{
    Executor executor;
    executor.ExecuteCommands("RMMRMMLLMMMRR");
    const std::string expectedStatus = "(2,1,S)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
  TEST(ExecutorTest, ExecuteCommands_when_without_init_Second) 
{
    Executor executor;
    executor.ExecuteCommands("MLMLMRMMRRM");
    const std::string expectedStatus = "(-2,0,E)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
  TEST(ExecutorTest, ExecuteCommands_when_with_init_First) 
{
    Executor executor(6,4,'W');
    executor.ExecuteCommands("MRMMLMMMRMMLRML");
    const std::string expectedStatus = "(2,9,W)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}
  TEST(ExecutorTest, ExecuteCommands_when_with_init_Second) 
{
    Executor executor(-9,-8,'S');
    executor.ExecuteCommands("MMRRMLLLMMRRMRLL");
    const std::string expectedStatus = "(-8,-9,S)";
    EXPECT_EQ(executor.GetStatus(), expectedStatus);
}


 