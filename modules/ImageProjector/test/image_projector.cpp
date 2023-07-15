//
// Created by jeong on 2023-07-16.
//

#include "gtest/gtest.h"
#include "ImageProject

/**
 * 1. ImageProjector는 class 형태여야한다.
 * 2. Input값은 항상 3D point's location(x, y, z), Extrinsic matrix, Intrinsic matrix이다.
 *      1. x, y, z는 double 자료형 형태로 주어진다.
 *      2. extrinsic matrix와 intrinsic matrix의 구성요소는 double 자료형이다.
 * 3. ImageProjector의 결과값은 u, v의 픽셀 위치값이 반환된다.
 *  1. u, v 는 double 자료형이어야한다.
 *
 *
 */

TEST(Test_Name_Major, Test_Name_Minor)
{
  constexpr bool evaluation = ture;
  EXPECT_EQ(evaluation, true);
}