#include <vector>
#include <functional>
#include <stdexcept>
#include "Line.h"

#pragma once

class Zipper {
	public:
		std::vector<std::string> Zip(const std::vector<std::vector<Line>>& collections, std::function<std::string(std::vector<Line> collection)> combine) const {
				if (collections.empty()) {
					throw std::invalid_argument("collections cannot be empty");
				}

				std::vector<std::string> zipped;
				std::vector<typename std::vector<Line>::const_iterator> iterators;

				for (const auto& collection : collections) {
					iterators.push_back(collection.begin());
				}

				while (iterators[0] != collections[0].end()) {
					std::vector<Line> nthElements = NextOfEach(iterators);
					std::string joined = combine(nthElements);
					zipped.push_back(joined);
				}

				return zipped;
			}

	private:
		std::vector<Line> NextOfEach(std::vector<typename std::vector<Line>::const_iterator>& iterators) const {
				std::vector<Line> nthElements;
				for (size_t i = 0; i < iterators.size(); ++i) {
					if (i != 0) {
						++iterators[i];
					}
					nthElements.push_back(*iterators[i]);
				}
				return nthElements;
			}
};
