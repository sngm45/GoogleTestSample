/**********************************************************
 * @file SampleTestCase.cpp
 * @brief Test cases
 * @author ngmrsng
 * @date 2016/07/11
 *********************************************************/

#include <SampleFunction.h>
#include <gtest/gtest.h>

/**
 * @fn
 * TEST(SampleFunctionUnitTest, hoge)
 * @brief Test cases
 * @param (SampleFunctionUnitTest) Target function for test
 * @param (hoge) ?
 * @return void
 * @sa 参照すべき関数を書けばリンクが貼れる
 * @detail 詳細な説明
 */
TEST(SampleFunctionUnitTest, hoge) {
	EXPECT_EQ(1, SampleFunction(1));
	EXPECT_EQ(2, SampleFunction(2));
	EXPECT_EQ(6, SampleFunction(3));	// error
	EXPECT_EQ(40320, SampleFunction(8));
}
