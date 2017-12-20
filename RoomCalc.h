#pragma once
#ifndef ROOM_CALC_H
#define ROOM_CALC_H

#define PROGRAM_NAME "RoomCalc"

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

float m_Length; 
float m_Width;
float m_Height;

float m_FloorArea;
float m_WallsArea;
float m_Volume;

float CalcFloorArea(float m_Length, float m_Width);

float CalcWallsArea(float m_Length, float m_Width, float m_Height);

float CalcVolume(float m_Length, float m_Width, float m_Height);

void DisplayResults(float m_Length, float m_Width, float m_Height, float m_FloorArea, float m_WallsArea, float m_Volume);

#endif
