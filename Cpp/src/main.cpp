#include <iostream>

#include "DigitScaler.h"
#include "DigitsSplitter.h"
#include "NumeralSystem.h"
#include "LcdDisplay.h"
#include "DigitPrinter.h"
#include "ScalingRepeater.h"
#include "Scaling.h"

int main(int argc, char* argv[]) {
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " <number> <scaling>" << std::endl;
		return 1;
	}

	NumeralSystem numeralSystem;
	Patterns patterns;
	DigitFactory digitFactory(patterns);
	DigitsSplitter digitsSplitter(numeralSystem, digitFactory);
	ScalingRepeater scalingRepeater;
	DigitScaler digitScaler(scalingRepeater);
	Zipper zipper;
	DigitPrinter digitPrinter(zipper);

	LcdDisplay lcdDisplay(digitsSplitter, digitScaler, digitPrinter);
	int number = std::stoi(argv[1]);

	Scaling scaling = Scaling::Of(std::stoi(argv[2]));
	try{
		std::cout << lcdDisplay.ToLcd(number, scaling) << std::endl;
	} catch(std::exception& exc){
		std::cout << exc.what() << std::endl;
	}
	return 0;
}
