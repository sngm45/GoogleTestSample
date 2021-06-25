/* ********************************************************
 * @file main.cpp
 * @brief main function
 * @author ngmrsng
 * @date 2016/07/11
 ******************************************************** */

#include <iostream>
#include <SampleFunction.h>

/*
 * @fn
 * int main(int argc, char **argv)
 * @brief main function
 * @param (int argc) not be used
 * @param (char **argv) not be used
 * @return 0
 * @sa 参照すべき関数を書けばリンクが貼れる
 * @detail 詳細な説明
 */
int main(int argc, char **argv)
{
	//! parameter
	int value = 3;

	value = SampleFunction(value);
	std::cout << "value: " << value << std::endl;

	return 0;
}
