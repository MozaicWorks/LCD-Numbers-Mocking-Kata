#include <string>
#include <vector>
#include <numeric>

#include "Digit.h"
#include "Zipper.h"
#include "Line.h"

#pragma once

class DigitPrinter {
	private:
		const std::string Newline = "\n";
		const Zipper& zipper;

	public:
		DigitPrinter(const Zipper& zipper) : zipper(zipper) {
		}

		std::string Render(const std::vector<Digit>& digits) const {
			if (digits.empty()) {
				throw std::invalid_argument("digits cannot be empty");
			}

			auto linesOfAllDigits = LinesOfAllDigits(digits);
			auto linesSideBySide = Zip(linesOfAllDigits);
			return Join(linesSideBySide);
		}

	private:
		std::vector<std::vector<Line>> LinesOfAllDigits(const std::vector<Digit>& digits) const {
			std::vector<std::vector<Line>> result;
			for (const auto& digit : digits) {
				result.push_back(digit.Lines());
			}
			return result;
		}

		std::vector<std::string> Zip(const std::vector<std::vector<Line>>& linesOfAllDigits) const {
			return zipper.Zip(linesOfAllDigits, [this](auto lines) {
					return Concat(lines);
					});
		}

		std::string Concat(const std::vector<Line>& lines) const {
			return std::accumulate(lines.begin(), lines.end(), std::string(), [](auto current, auto next)
					{
					return current + next.ToString();
					});
		}

		std::string Join(const std::vector<std::string>& lines) const {
			return std::accumulate(lines.begin(), lines.end(), std::string(),
					[this](auto current, auto next) {
					return current + Newline + next;
					}) + Newline;
		}
};
