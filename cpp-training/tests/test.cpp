#include <gtest/gtest.h>

#include "executormpl.hpp"

bool operator==(const Pose& lhs, const Pose& rhs) 
{   
    return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading); 
}

TEST(Executor_type_Test, return_defalut_status_when_without_init_and_command)
{
    
    auto executor = std::make_unique<Executormpl>();
    const Pose target({0,0,'N'});
    ASSERT_EQ(target, executor->Query()); 
}


TEST(Executor_type_Test, return_init_status_when_with_init)
{
    const Pose initPose({7,4,'W'});
    auto executor = std::make_unique<Executormpl>(initPose,Car);
    const Pose target({7,4,'W'});
    ASSERT_EQ(target, executor->Query());
}
//MoveForward Test
TEST(Executor_type_Test, should_return_x_minus_2_when_Command_BM_with_SportsCar_and_E_Heading) 
{
    Executormpl executor({-5,6,'E'},SportsCar);
    executor.Execute("BM");
    const Pose target({-7,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_x_plus_4_when_Command_FM_with_init_and_E_Headingh_SportsCar_) 
{
    Executormpl executor({7,6,'E'},SportsCar);
    executor.Execute("FM");
    const Pose target({11,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_x_minus_4_when_Command_BFM_with_init_and_E_Headingh_SportsCar_) 
{
    Executormpl executor({-6,5,'E'},SportsCar);
    executor.Execute("BFM");
    const Pose target({-10,5,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_y_plus_2_when_Command_BBM_with_init_and_N_Headingh_SportsCar_) 
{
    Executormpl executor({6,-7,'N'},SportsCar);
    executor.Execute("BBM");
    const Pose target({6,-5,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_y_plus_2_when_Command_FFM_with_init_and_N_Headingh_SportsCar_) 
{
    Executormpl executor({9,-7,'N'},SportsCar);
    executor.Execute("FFM");
    const Pose target({9,-5,'N'});
    EXPECT_EQ(executor.Query(), target);
}
//TrunLeft Test
TEST(Executor_type_Test, should_return_y_plus_1_heading_S_when_Command_BL_with_init_and_E_Headingh_SportsCar_) 
{
    Executormpl executor({4,7,'E'},SportsCar);
    executor.Execute("BL");
    const Pose target({4,8,'S'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test,should_return_x_plus_1_y_plus_1_heading_N_when_Command_FL_with_init_and_E_Headingh_SportsCar_) 
{
    Executormpl executor({4,7,'E'},SportsCar);
    executor.Execute("FL");
    const Pose target({5,8,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_x_minus_1_y_plus_1_heading_S_when_Command_BFL_with_init_and_E_Headingh_SportsCar_) 
{
    Executormpl executor({-4,7,'E'},SportsCar);
    executor.Execute("BFL");
    const Pose target({-5,8,'S'});
    EXPECT_EQ(executor.Query(), target);
}

//TrunRight Test
TEST(Executor_type_Test,should_return_y_minus_1_heading_N_when_Command_BR_with_init_and_E_Headingh_SportsCar_)
{    
    Executormpl executor({8,6,'E'},SportsCar);
    executor.Execute("BR");
    const Pose target({8,5,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_y_minus_1_x_plus_1_heading_S_when_Command_FR_with_init_and_S_Headingh_SportsCar_) 
{
    Executormpl executor({8,6,'E'},SportsCar);
    executor.Execute("FR");
    const Pose target({9,5,'S'});
    EXPECT_EQ(executor.Query(), target);
}
 TEST(Executor_type_Test, should_return_x_minus_1_y_minus_1_heading_N_when_Command_BFR_with_init_and_E_Headingh_SportsCar_) 
{

    Executormpl executor({8,6,'E'},SportsCar);
    executor.Execute("BFR");
    const Pose target({7,5,'N'});
    EXPECT_EQ(executor.Query(), target);
}
//MoveForward Test
TEST(Executor_type_Test, should_return_x_minus_1_when_Command_BM_with_init_and_E_Heading_Bus) 
{
    Executormpl executor({-5,6,'E'},Bus);
    executor.Execute("BM");
    const Pose target({-6,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_x_plus_2_when_Command_FM_with_init_and_E_Heading_Bus) 
{
    Executormpl executor({7,6,'E'},Bus);
    executor.Execute("FM");
    const Pose target({9,6,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_x_minus_2_when_Command_BFM_with_init_and_E_Heading_Bus) 
{
    Executormpl executor({-6,5,'E'},Bus);
    executor.Execute("BFM");
    const Pose target({-8,5,'E'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_y_plus_1_when_Command_BBM_with_init_and_N_Heading_Bus) 
{
    Executormpl executor({6,-7,'N'},Bus);
    executor.Execute("BBM");
    const Pose target({6,-6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_y_plus_1_when_Command_FFM_with_init_and_N_Heading_Bus) 
{
    Executormpl executor({9,-7,'N'},Bus);
    executor.Execute("FFM");
    const Pose target({9,-6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
//TrunLeft Test
TEST(Executor_type_Test, should_return_x_minus_1_heading_S_when_Command_BL_with_init_and_E_Heading_Bus) 
{
    Executormpl executor({4,7,'E'},Bus);
    executor.Execute("BL");
    const Pose target({3,7,'S'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test,should_return_x_plus_1_heading_N_when_Command_FL_with_init_and_E_Heading_Bus) 
{
    Executormpl executor({4,7,'E'},Bus);
    executor.Execute("FL");
    const Pose target({6,7,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_x_minus_2_heading_S_when_Command_BFL_with_init_and_E_Heading_Bus) 
{
    Executormpl executor({-4,7,'E'},Bus);
    executor.Execute("BFL");
    const Pose target({-6,7,'S'});
    EXPECT_EQ(executor.Query(), target);
}

//TrunRight Test
TEST(Executor_type_Test,should_return_x_minus_1_heading_N_when_Command_BR_with_init_and_E_Heading_Bus)
{    
    Executormpl executor({8,6,'E'},Bus);
    executor.Execute("BR");
    const Pose target({7,6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
TEST(Executor_type_Test, should_return_x_plus_2_heading_S_when_Command_FR_with_init_and_S_Heading_Bus) 
{
    Executormpl executor({8,6,'E'},Bus);
    executor.Execute("FR");
    const Pose target({10,6,'S'});
    EXPECT_EQ(executor.Query(), target);
}
 TEST(Executor_type_Test, should_return_x_minus_2_heading_N_when_Command_BFR_with_init_and_E_Heading_Bus) 
{

    Executormpl executor({8,6,'E'},Bus);
    executor.Execute("BFR");
    const Pose target({6,6,'N'});
    EXPECT_EQ(executor.Query(), target);
}
 