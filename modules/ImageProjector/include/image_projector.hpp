//
// Created by jeong on 2023-07-16.
//

#ifndef SVSLAM_IMAGE_PROJECTOR_HPP
#define SVSLAM_IMAGE_PROJECTOR_HPP

#define USING_EASY_PROFILER

#include "easy/profiler.h"
#include "spdlog/spdlog.h"
#include "Eigen/Dense"

struct LandmarkPosition {
	double x;
	double y;
	double z;
};

struct IntrinsicMatrix {
	double fx;
	double fy;
	double cx;
	double cy;
};

struct ExtrinsicMatrix {
	Eigen::Matrix3d rotation_matrix;
	Eigen::Vector3d translation;
};

struct ProjectedPoints {
	double u;
	double v;
};

ProjectedPoints
project_points(const LandmarkPosition &point3D, const IntrinsicMatrix &intrinsics, const ExtrinsicMatrix &extrinsic) {

	std::ignore = point3D;
	std::ignore = intrinsics;
	std::ignore = extrinsic;
	return ProjectedPoints{};
}

#endif  // SVSLAM_IMAGE_PROJECTOR_HPP
