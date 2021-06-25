/**********************************************************
 * @file SampleFunction.cpp
 * @brief Test target
 * @author ngmrsng
 * @date 2016/07/11
 *********************************************************/

#include <SampleFunction.h>

/**
 * @fn
 * int SampleFunction(int n)
 * @brief 要約説明
 * @param (引数名) 引数の説明
 * @param (引数名) 引数の説明
 * @return 戻り値の説明
 * @sa 参照すべき関数を書けばリンクが貼れる
 * @detail 詳細な説明
 */
// calculate 1 * 2 * 3 * ... * n
int SampleFunction(int n) {
	if(n == 0) return 1;
	return n * SampleFunction(n - 1);
};
