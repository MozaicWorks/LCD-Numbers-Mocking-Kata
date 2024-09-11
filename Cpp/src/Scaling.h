#include <stdexcept>
#include <functional>
#include <string>

#pragma once

class Scaling {
	private:
		int times;

		Scaling(int times) {
			if (times <= 0) {
				throw std::invalid_argument("scaling factor must be >= 1");
			}
			this->times = times;
		}

	public:
		static const Scaling None;
		static const Scaling Two;

		static Scaling Of(int t) {
			return Scaling(t);
		}

		bool HasNone() const {
			return times == 1;
		}

		void Times(const std::function<void()>& block) const {
			if (!block) {
				throw std::invalid_argument("block cannot be null");
			}

			for (int i = 0; i < times; ++i) {
				block();
			}
		}

		bool operator==(const Scaling& other) const {
			return this->times == other.times;
		}

		bool operator!=(const Scaling& other) const {
			return !(*this == other);
		}

		std::size_t GetHashCode() const {
			return std::hash<int>{}(times);
		}

		std::string ToString() const {
			return std::to_string(times);
		}
};


