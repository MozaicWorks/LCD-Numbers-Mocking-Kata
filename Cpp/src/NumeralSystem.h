#include <vector>
#include <stdexcept>
#include <algorithm>

#pragma once

class NumeralSystem {
	private:
		int base_;

	public:
		NumeralSystem() : NumeralSystem(10) {}

		NumeralSystem(int base_) {
			if (base_ < 2) {
				throw std::invalid_argument("Smallest base is binary; base=" + std::to_string(base_));
			}
			this->base_ = base_;
		}

		std::vector<int> DigitsOf(int value) const {
			if (value < 0) {
				throw std::invalid_argument("negative number " + std::to_string(value));
			}

			std::vector<int> digits;
			int remainder = value;
			while (remainder > 0) {
				digits.push_back(remainder % base_);
				remainder /= base_;
			}

			std::reverse(digits.begin(), digits.end());
			return digits;
		}
};
