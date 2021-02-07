#pragma once
#include "GUI.h"
#include "PositionCalculation.h"

using namespace System;
using namespace System::Drawing;
using namespace PositionCalculation;

bool CheckInRange(int, int, int);

void FindSelectedAnnotation(Point^);

void ResizeAnnotation(Point^);

void QuickResizeAnnotation(int, int, int);