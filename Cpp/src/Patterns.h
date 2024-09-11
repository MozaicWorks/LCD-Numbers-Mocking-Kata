#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <memory>
#include <algorithm>

#include "IPatterns.h"

#pragma once

class Patterns : public IPatterns {
	private:
		std::unordered_map<int, std::vector<Line>> lcdByDigit;

		void Put(int digit, const std::vector<Line>& lines) {
			if (lcdByDigit.find(digit) != lcdByDigit.end()) {
				throw std::invalid_argument("duplicate pattern definition for digit " + std::to_string(digit));
			}
			lcdByDigit[digit] = lines;
		}

	public:
		Patterns() {
			Put(0, { Line(" - "), Line("| |"), Line("   "), Line("| |"), Line(" - ") });
			Put(1, { Line("   "), Line("  |"), Line("   "), Line("  |"), Line("   ") });
			Put(2, { Line(" - "), Line("  |"), Line(" - "), Line("|  "), Line(" - ") });
			Put(3, { Line(" - "), Line("  |"), Line(" - "), Line("  |"), Line(" - ") });
			Put(4, { Line("   "), Line("| |"), Line(" - "), Line("  |"), Line("   ") });
			Put(5, { Line(" - "), Line("|  "), Line(" - "), Line("  |"), Line(" - ") });
			Put(6, { Line(" - "), Line("|  "), Line(" - "), Line("| |"), Line(" - ") });
			Put(7, { Line(" - "), Line("  |"), Line("   "), Line("  |"), Line("   ") });
			Put(8, { Line(" - "), Line("| |"), Line(" - "), Line("| |"), Line(" - ") });
			Put(9, { Line(" - "), Line("| |"), Line(" - "), Line("  |"), Line(" - ") });
		}

		std::vector<Line> Of(int digit) const override {
			auto it = lcdByDigit.find(digit);
			if (it == lcdByDigit.end()) {
				throw std::invalid_argument("no pattern defined for digit " + std::to_string(digit));
			}
			return it->second;
		}
};
