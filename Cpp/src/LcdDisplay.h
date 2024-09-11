#include <string>

#include "DigitsSplitter.h"
#include "DigitScaler.h"
#include "DigitPrinter.h"
#include "Scaling.h"

#pragma once

class LcdDisplay {
	private:
		const DigitsSplitter& digitsSplitter;
		const DigitScaler& digitScaler;
		const DigitPrinter& digitPrinter;

	public:
		LcdDisplay(const DigitsSplitter& digitsSplitter, const DigitScaler& digitScaler, const DigitPrinter& digitPrinter) : digitsSplitter(digitsSplitter), digitScaler(digitScaler), digitPrinter(digitPrinter){
		}

		std::string ToLcd(const int number, const Scaling& scaling) const {
			auto digits = digitsSplitter.Convert(number);
			auto scaled = digitScaler.Scale(digits, scaling);
			return digitPrinter.Render(scaled);
		}
};

