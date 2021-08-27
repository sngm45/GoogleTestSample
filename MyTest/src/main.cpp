/**********************************************************
 * @file main.cpp
 * @brief main function for gtest
 * @author sngm45
 * @date 2021/08/27
 *********************************************************/

#include <config.h>

#ifdef ENABLE_GTEST
#include <gtest/gtest.h>
#endif

#ifdef ENABLE_GMOCK
#include <gmock/gmock.h>
#endif

/**
 * @fn
 * int main(int argc, char **argv)
 * @brief main function for gtest
 * @return result of test
 * @sa RUN_ALL_TESTS()
 * @detail 詳細な説明
 */
int main(int argc, char **argv)
{
	//! result of test
	int lResult = 0;

#if defined(ENABLE_GTEST)
	::testing::InitGoogleTest(&argc, argv);
#endif

#if defined(ENABLE_GMOCK)
	::testing::InitGoogleMock(&argc, argv);
#endif

#if defined(ENABLE_GTEST) || defined(ENABLE_GMOCK)
	lResult =  RUN_ALL_TESTS();
#endif

	return lResult;
}
