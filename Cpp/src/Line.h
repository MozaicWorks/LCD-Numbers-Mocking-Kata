#include <string>
#include <stdexcept>

#include "ScalingRepeater.h"
#include "Scaling.h"

#pragma once

class Line {
	private:
		std::string line;

	public:
		Line(const std::string& line) {
			if (line.empty()) {
				throw std::invalid_argument("line cannot be null");
			}
			this->line = line;
		}

		Line ScaleHorizontal(const ScalingRepeater& repeater, const Scaling& scaling) const {

			char firstChar = line[0];
			char middleChar = line[1];
			char lastChar = line[2];

			std::string scaledLine = firstChar + repeater.Repeat(middleChar, scaling) + lastChar;
			return Line(scaledLine);
		}

		bool operator==(const Line& other) const {
			return this->line == other.line;
		}

		std::string ToString() const {
			return line;
		}
};
