// LevelHelpers.h - a few handy tools to ease using levels.
// The important thing is the XXXPos functions, which convert
// image positions from one level to another. Use these whenever
// transforming positions to ensure consistent operation!!

#pragma once

#include "additionalUtility.h"

// Set of global colours useful for drawing stuff:
extern cv::Vec3d gavLevelColors[];
// (These are filled in in KeyFrame.cc)

// What is the scale of a level?
inline int LevelScale(int nLevel)
{
  return 1 << nLevel;
}

// 1-D transform to level zero:
inline double LevelZeroPos(double dLevelPos, int nLevel)
{
  return (dLevelPos + 0.5) * LevelScale(nLevel) - 0.5;
}

// 2-D transforms to level zero:
inline cv::Vec2d LevelZeroPos(cv::Vec2d v2LevelPos, int nLevel)
{
  cv::Vec2d v2Ans(LevelZeroPos(v2LevelPos[0], nLevel), 
	              LevelZeroPos(v2LevelPos[1], nLevel));
  return v2Ans;
}

inline cv::Vec2d LevelZeroPos(cv::Point irLevelPos, int nLevel) 
{
  cv::Vec2d v2Ans(LevelZeroPos(irLevelPos.x, nLevel),
	              LevelZeroPos(irLevelPos.y, nLevel));
  return v2Ans;
}

// 1-D transform from level zero to level N:
inline double LevelNPos(double dRootPos, int nLevel)
{
  return (dRootPos + 0.5) / LevelScale(nLevel) - 0.5;
}

// 2-D transform from level zero to level N:
inline cv::Vec2d LevelNPos(cv::Vec2d v2RootPos, int nLevel)
{
  cv::Vec2d v2Ans(LevelNPos(v2RootPos[0], nLevel),
                  LevelNPos(v2RootPos[1], nLevel));
  return v2Ans;
}