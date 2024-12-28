#include <gtest/gtest.h>

#include "executormpl.hpp"

bool operator==(const Pose& lhs, const Pose& rhs) 
{   
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading); 
}

TEST(ExecutorTest, return_defalut_status_when_without_init_and_command)
{
    
    auto executor = std::make_unique<Executormpl>();
    const Pose target({0,0,'N'});
    ASSERT_EQ(target, executor->Query()); 
}


TEST(ExecutorTest, return_init_status_when_with_init)
{
    const Pose initPose({7,4,'W'});
    auto executor = std::make_unique<Executormpl>(initPose);
    const Pose target({7,4,'W'});
    ASSERT_EQ(target, executor->Query());
}
//MoveForward Test
TEST(ExecutorTest, should_return_x_plus_1_when_Command_MoveForwardwith_init_and_E_Heading) 
{
    Executormpl executor({-5,6,'E'});
    executor.Execute("M");
    const Pose target({-4,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_x_minus_1_when_Command_MoveForward_with_init_and_W_Heading) 
{
    Executormpl executor({7,6,'W'});
    executor.Execute("M");
    const Pose target({6,6,'W'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_y_plus_1_when_Command_MoveForwar_with_init_and_N_Heading) 
{
    Executormpl executor({-6,5,'N'});
    executor.Execute("M");
    const Pose target({-6,6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_y_minus_1_when_Command_MoveForward_with_init_and_S_Heading) 
{
    Executormpl executor({6,-7,'S'});
    executor.Execute("M");
    const Pose target({6,-8,'S'});
    EXPECT_EQ(executor.Query(), target);
}
//TrunLeft Test
TEST(ExecutorTest, should_return_heading_E_when_Command_TrunLeft_with_init_and_S_Heading) 
{
    Executormpl executor({4,7,'S'});
    executor.Execute("L");
    const Pose target({4,7,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest,should_return_heading_N_when_Command_TrunLeft_with_init_and_E_Heading) 
{
    Executormpl executor({4,7,'E'});
    executor.Execute("L");
    const Pose target({4,7,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_heading_W_when_Command_TrunLeft_with_init_and_N_Heading) 
{
    Executormpl executor({-4,7,'N'});
    executor.Execute("L");
    const Pose target({-4,7,'W'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_heading_S_when_Command_TrunLeft_with_init_and_W_Heading) 
{
    Executormpl executor({4,-7,'W'});
    executor.Execute("L");
    const Pose target({4,-7,'S'});
    EXPECT_EQ(executor.Query(), target);
}
//TrunRight Test
TEST(ExecutorTest,should_return_heading_W_when_Command_TrunRight_with_init_and_S_Heading)
{    
    Executormpl executor({8,6,'S'});
    executor.Execute("R");
    const Pose target({8,6,'W'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_heading_N_when_Command_TrunRight_with_init_and_W_Heading) 
{
    Executormpl executor({8,6,'W'});
    executor.Execute("R");
    const Pose target({8,6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
 TEST(ExecutorTest, should_return_heading_E_when_Command_TrunRight_with_init_and_N_Heading) 
{

    Executormpl executor({8,6,'N'});
    executor.Execute("R");
    const Pose target({8,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
 TEST(ExecutorTest, should_return_heading_S_when_Command_TrunRight_with_init_and_E_Heading) 
{
    Executormpl executor({8,6,'E'});
    executor.Execute("R");
    const Pose target({8,6,'S'});
    EXPECT_EQ(executor.Query(), target);
}
//ExecuteCommands Test 
  TEST(ExecutorTest, should_return_x_plus_2_y_plus_1_S_heading_when_ExecuteCommands_RMMRMMLLMMMRR_without_init_First) 
{

    Executormpl executor;
    executor.Execute("RMMRMMLLMMMRR");
    const Pose target({2,1,'S'});
    EXPECT_EQ(executor.Query(), target);
}
  TEST(ExecutorTest,should_return_x_minus_2_E_heading_when_ExecuteCommands_MLMLMRMMRRM_without_init_Second) 
{
    Executormpl executor;
    executor.Execute("MLMLMRMMRRM");
    const Pose target({-2,0,'E'});
    EXPECT_EQ(executor.Query(), target);

}
  TEST(ExecutorTest, should_return_x_minus_4_y_plus_5_W_heading_when_ExecuteCommands_MRMMLMMMRMMLRML_with_init_First) 
{
    Executormpl executor({6,4,'W'});
    executor.Execute("MRMMLMMMRMMLRML");
    const Pose target({2,9,'W'});
    EXPECT_EQ(executor.Query(), target);
}
  TEST(ExecutorTest, should_return_x_minus_1_y_minus_1_S_heading_when_ExecuteCommands_MMRRMLLLMMRRMRLL_with_init_Second) 
{
    Executormpl executor({-9,-8,'S'});
    executor.Execute("MMRRMLLLMMRRMRLL");
    const Pose target({-8,-9,'S'});
    EXPECT_EQ(executor.Query(), target);

}


TEST(ExecutorTest,should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E) 
{
     Executormpl executor({-9,-8,'E'});
    executor.Execute("FM");
    const Pose target({-7,-8,'E'});
    EXPECT_EQ(executor.Query(), target);
}

TEST(ExecutorTest,should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
{
     Executormpl executor({9,9,'E'});
    executor.Execute("FL");
    const Pose target({10,9,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest,should_return_S_and_x_plus_1_given_status_is_fast_given_command_is_R_and_facing_is_E)
{
     Executormpl executor({6,6,'E'});
    executor.Execute("FR");
    const Pose target({7,6,'S'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest,should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
{
     Executormpl executor({6,6,'N'});
    executor.Execute("FFM");
    const Pose target({6,7,'N'});
    EXPECT_EQ(executor.Query(), target);
}