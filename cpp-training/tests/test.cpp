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
TEST(ExecutorTest, should_return_x_minus_1_when_Command_BM_with_init_and_E_Heading) 
{
    Executormpl executor({-5,6,'E'});
    executor.Execute("BM");
    const Pose target({-6,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_x_plus_2_when_Command_FM_with_init_and_E_Heading) 
{
    Executormpl executor({7,6,'E'});
    executor.Execute("FM");
    const Pose target({9,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_x_minus_2_when_Command_BFM_with_init_and_E_Heading) 
{
    Executormpl executor({-6,5,'E'});
    executor.Execute("BFM");
    const Pose target({-8,5,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_y_plus_1_when_Command_BBM_with_init_and_N_Heading) 
{
    Executormpl executor({6,-7,'N'});
    executor.Execute("BBM");
    const Pose target({6,-6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_y_plus_1_when_Command_FFM_with_init_and_N_Heading) 
{
    Executormpl executor({9,-7,'N'});
    executor.Execute("FFM");
    const Pose target({9,-6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
//TrunLeft Test
TEST(ExecutorTest, should_return_heading_S_when_Command_BL_with_init_and_E_Heading) 
{
    Executormpl executor({4,7,'E'});
    executor.Execute("BL");
    const Pose target({4,7,'S'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest,should_return_x_plus_1_heading_N_when_Command_FL_with_init_and_E_Heading) 
{
    Executormpl executor({4,7,'E'});
    executor.Execute("FL");
    const Pose target({5,7,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_x_minus_1_heading_S_when_Command_BFL_with_init_and_E_Heading) 
{
    Executormpl executor({-4,7,'E'});
    executor.Execute("BFL");
    const Pose target({-5,7,'S'});
    EXPECT_EQ(executor.Query(), target);
}

//TrunRight Test
TEST(ExecutorTest,should_return_heading_N_when_Command_BR_with_init_and_E_Heading)
{    
    Executormpl executor({8,6,'E'});
    executor.Execute("BR");
    const Pose target({8,6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(ExecutorTest, should_return_x_plus_1_heading_S_when_Command_FR_with_init_and_S_Heading) 
{
    Executormpl executor({8,6,'E'});
    executor.Execute("FR");
    const Pose target({9,6,'S'});
    EXPECT_EQ(executor.Query(), target);
}
 TEST(ExecutorTest, should_return_x_minus_1_heading_N_when_Command_BFR_with_init_and_E_Heading) 
{

    Executormpl executor({8,6,'E'});
    executor.Execute("BFR");
    const Pose target({7,6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
 