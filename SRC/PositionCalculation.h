#pragma once

using namespace System::Collections::Generic;

namespace PositionCalculation{
	///Calculate point relative to image, for rendering
	int CalculatePos(int, int, float);

	///Calculate point relative to image, for placement
	int CalculatePosInverse(int, int, float);

	List<int>^ ReorderVertices(List<int>^);
}