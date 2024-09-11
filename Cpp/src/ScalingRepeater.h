#include <vector>
#include <sstream>

#include "Scaling.h"

#pragma once

class ScalingRepeater {
	public:
		template <typename T>
		std::vector<T> Repeat(const T& element, const Scaling& scaling) const {
			std::vector<T> elements;
			scaling.Times([&elements, element](){ elements.push_back(element); });
			return elements;
		}

		std::string Repeat(const char aChar, const Scaling& scaling) const {
			std::ostringstream acc;
			scaling.Times([&acc, aChar]() { acc << aChar; });
			return acc.str();
		}
};
