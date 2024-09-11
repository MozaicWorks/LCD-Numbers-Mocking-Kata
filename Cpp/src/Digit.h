#include <vector>
#include <stdexcept>
#include "Line.h"
#include "Patterns.h"

#pragma once

class Digit {
	private:
		const int digit;
		const std::vector<Line>& lines;

	public:
		Digit(const int digit, const Patterns& patterns)
			: Digit(digit, patterns.Of(digit)) {}

		Digit(const int digit, const std::vector<Line>& lines) : digit(digit), lines(lines) {
			if (lines.empty()) {
				throw std::invalid_argument("lines cannot be null");
			}
		}

		std::vector<Line> Lines() const {
			return lines;
		}

		Digit Scale(const std::vector<Line>& scaledLines) const {
			if (scaledLines.empty()) {
				throw std::invalid_argument("scaledLines cannot be null");
			}

			int linesCount = lines.size();
			int scaledCount = scaledLines.size();
			if (scaledCount < linesCount) {
				throw std::invalid_argument("Scaled lines must be more than original ones: " + std::to_string(scaledCount) + ">=" + std::to_string(linesCount));
			}

			return Digit(digit, scaledLines);
		}

		bool operator==(const Digit& other) const {
			return this->digit == other.digit;
		}

		std::string ToString() const {
			return std::to_string(digit);
		}
};
