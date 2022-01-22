#include <gtest/gtest.h>
#include <glog/logging.h>
#include <gflags/gflags.h>

TEST(Math, Adding)
{
    LOG(INFO) << "Hello World!";
    EXPECT_EQ(2 + 2, 4);
}