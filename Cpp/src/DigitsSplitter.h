#include <memory>
#include <stdexcept>

#include "NumeralSystem.h"
#include "DigitFactory.h"

#pragma once

class DigitsSplitter {
	private:
		const NumeralSystem& numeralSystem;
		const DigitFactory& digitFactory;

	public:
		DigitsSplitter(const NumeralSystem& numeralSystem, const DigitFactory& digitFactory) : numeralSystem(numeralSystem), digitFactory(digitFactory) {}

		std::vector<Digit> Convert(int number) const {
			auto numeralDigits = numeralSystem.DigitsOf(number);
			std::vector<Digit> lcdDigits;
			std::transform(numeralDigits.begin(), numeralDigits.end(), std::back_inserter(lcdDigits),
					[this](auto digit) {
					return digitFactory.Create(digit);
					});
			return lcdDigits;
		}
};

