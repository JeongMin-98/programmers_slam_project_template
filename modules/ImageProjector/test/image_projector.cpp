//
// Created by jeong on 2023-07-16.
//
#include <memory>
#include "gtest/gtest.h"
#include "image_projector.hpp"
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

TEST(Image_Projector, constructor) {

	LandmarkPosition point3D = {1.0, 0.0, 0.0};
	IntrinsicMatrix intrinsic = {1.0, 1.0, 320.0, 240.0};
	ExtrinsicMatrix extrinsic = {Eigen::Matrix3d::Identity(), Eigen::Vector3d{0.0, 0.0, 0.0}};

	// class
//	const auto projector = std::make_shared<ImageProjector>(point3D, intrinsic, extrinsic);
//	EXPECT_NE(projector, nullptr);

	constexpr ProjectedPoints uv = {1.0, 1.0};

	const auto projected_point = project_points(point3D, intrinsic, extrinsic);
	EXPECT_EQ(projected_point.u, uv.u);
	EXPECT_EQ(projected_point.v, uv.v);

}
