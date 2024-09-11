#include <vector>

#include "Line.h"

#pragma once

class IPatterns {
	public:
		virtual ~IPatterns() = default;
		virtual std::vector<Line> Of(int digit) const = 0;
};

