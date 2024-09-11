#include "Digit.h"

#pragma once

class DigitFactory {
	private:
		const Patterns& patterns;

	public:
		DigitFactory(const Patterns& patterns): patterns(patterns) {}

		Digit Create(int digit) const {
			return Digit(digit, patterns);
		}
};
