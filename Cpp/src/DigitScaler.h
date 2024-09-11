#include <memory>
#include <vector>
#include <algorithm>

#include "Digit.h"
#include "ScalingRepeater.h"

#pragma once

class DigitScaler {
	private:
		const ScalingRepeater& repeater;

	public:
		DigitScaler(const ScalingRepeater& repeater ) : repeater(repeater) {}

		std::vector<Digit> Scale(const std::vector<Digit>& digits, const Scaling& scaling) const {
			if (digits.empty()) {
				throw std::invalid_argument("digits cannot be empty");
			}

			std::vector<Digit> scaledDigits;
			std::transform(digits.begin(), digits.end(), std::back_inserter(scaledDigits),
					[this, scaling](const Digit& digit) {
						return Scale(digit, scaling);
					});
			return scaledDigits;
		}

	private:
		Digit Scale(const Digit& digit, const Scaling& scaling) const {
			if (scaling.HasNone()) {
				return digit;
			}

			std::vector<Line> scaled;
			bool oddLine = true;
			for (const auto& line : digit.Lines()) {
				Line scaledLine = line.ScaleHorizontal(repeater, scaling);
				if (oddLine) {
					scaled.push_back(scaledLine);
				} else {
					auto repeatedLines = repeater.Repeat(scaledLine, scaling);
					scaled.insert(scaled.end(), repeatedLines.begin(), repeatedLines.end());
				}
				oddLine = !oddLine;
			}

			return digit.Scale(scaled);
		}
};

