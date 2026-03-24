#include "long_number.hpp"

using drw::LongNumber;
		
LongNumber::LongNumber() {
	this->numbers = new int[1];
	this->numbers[0] = 0;
	this->length = 1;
	this->sign = 1;
}

LongNumber::LongNumber(int length, int sign) {
	this->numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
	this->length = length;
	this->sign = sign;
}

LongNumber::LongNumber(const char* const str) {
	if (str[0] == '-') {
		this->sign = 0;
	} else {
		this->sign = 1;
	}

	this->length = get_length(str);

	if (str[0] == '+' or str[0] == '-') {
		this->numbers = new int[this->length];
		for (int i = 0; i < this->length; i++) {
			this->numbers[i] = str[i + 1] - '0';
		}
	} else {
		this->numbers = new int[this->length];
		for (int i = 0; i < this->length; i++) {
			this->numbers[i] = str[i] - '0';
		}
	}

	this->remove_leading_zeros();
}

LongNumber::LongNumber(const int x) {
	if (x == 0) {
		this->sign = 1;
		this->length = 1;
		this->numbers = new int[1];
		this->numbers[0] = 0;
		return;
	}

	if (x > 0) {
		this->sign = 1;
	} else {
		this->sign = 0;
	}

	int temp = abs(x);

	this->length = 0;
	int len = temp;
	while (len > 0) {
		this->length++;
		len /= 10;
	}

	this->numbers = new int[this->length];

	for (int i = this->length - 1; i >= 0; i--) {
		this->numbers[i] = temp % 10;
		temp /= 10;
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	this->sign = x.sign;
	this->length = x.length;
	this->numbers = new int[this->length];
	for (int i = 0; i < this->length; i++) {
		this->numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	this->sign = x.sign;
	this->length = x.length;
	this->numbers = x.numbers;

	x.sign = 1;
	x.length = 0;
	x.numbers = nullptr;
}

LongNumber::~LongNumber() {
	if (this->numbers != nullptr) {
		delete[] this->numbers;
	}

	this->numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	delete[] this->numbers;

	if (str[0] == '-') {
		this->sign = 0;
	} else {
		this->sign = 1;
	}

	this->length = get_length(str);

	if (str[0] == '+' or str[0] == '-') {
		this->numbers = new int[length];
		for (int i = 0; i < this->length; i++) {
			this->numbers[i] = str[i + 1] - '0';
		}
	} else {
		this->numbers = new int[length];
		for (int i = 0; i < this->length; i++) {
			this->numbers[i] = str[i] - '0';
		}
	}

	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	this->sign = x.sign;
	this->length = x.length;

	delete[] this->numbers;
	this->numbers = new int[this->length];
	for (int i = 0; i < this->length; i++) {
		this->numbers[i] = x.numbers[i];
	}

	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	if (this != &x) {
		delete[] this->numbers;
		this->sign = x.sign;
		this->length = x.length;
		this->numbers = x.numbers;

		x.sign = 1;
		x.length = 0;
		x.numbers = nullptr;
	}
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (this->sign != x.sign) {
		return false;
	} else if (this->length != x.length) {
		return false;
	} else {
		for (int i = 0; i < x.length; i++) {
			if (this->numbers[i] != x.numbers[i]) {
				return false;
			}
		}
	}

	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(x == *this);
}
bool LongNumber::operator > (const LongNumber& x) const {
	if (this->sign == 1 and x.sign == 0) {
		return !x.is_zero();
	}

	if (this->sign == 0 and x.sign == 1) {
		return false;
	}

	if (this->is_zero() and x.is_zero()) {
		return false;
	}

	if (this->sign == 1) {
		if (this->length != x.length) {
			return this->length > x.length;
		}
		for (int i = 0; i < this->length; i++) {
			if (this->numbers[i] != x.numbers[i]) {
				return this->numbers[i] > x.numbers[i];
			}
		}
		return false;
	}

	if (this->length != x.length) {
		return this->length < x.length;
	}
	for (int i = 0; i < this->length; i++) {
		if (this->numbers[i] != x.numbers[i]) {
			return this->numbers[i] < x.numbers[i];
		}
	}
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	if ((*this > x) or (*this == x)) {
		return false;
	}

	return true;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	int max_length;

	if (this->length > x.length) {
		max_length = this->length;
	} else {
		max_length = x.length;
	}

	if (this->is_negative() != x.is_negative()) {
		if (x.is_negative()) {
			LongNumber x_copy(x);
			x_copy.sign = 1;

			return *this - x_copy;
		}

		else {
			LongNumber this_copy(*this);
			this_copy.sign = 1;

			return x - this_copy;
		}
	}

	LongNumber result(max_length + 1, x.sign);

	int i = this->length - 1;
	int j = x.length - 1;
	int k = max_length;

	while ((i >= 0) and (j >= 0)) {
		result.numbers[k] = this->numbers[i] + x.numbers[j];
		i--;
		j--;
		k--;
	}

	while (i >= 0) {
		result.numbers[k] = this->numbers[i];
		i--;
		k--;
	}

	while (j >= 0) {
		result.numbers[k] = x.numbers[j];
		j--;
		k--;
	}

	for (int i = max_length; i > 0; i--) {
		if (result.numbers[i] > 9) {
			result.numbers[i - 1] += 1;
			result.numbers[i] -= 10;
		}
	}

	result.remove_leading_zeros();
	return result;
}


LongNumber LongNumber::operator - (const LongNumber& x) const {
	LongNumber result;

	if (this->is_negative() != x.is_negative()) {
		if (x.is_negative()) {
			LongNumber x_copy = x;
			x_copy.sign = 1;
			result = *this + x_copy;
		} else {
			LongNumber this_copy = *this;
			this_copy.sign = 1;
			result = x + this_copy;
			result.sign = 0;
		}
	}

	else if (this->is_negative()) {
		LongNumber this_copy = *this;
		LongNumber x_copy = x;
		this_copy.sign = 1;
		x_copy.sign = 1;

		result = x_copy - this_copy;
	}

	else {
		if (*this < x) {
			result = x - *this;
			result.sign = 0;
		}

		else {
			int max_length = this->length;
			result = LongNumber(max_length, 1);

			int i = this->length - 1;
			int j = x.length - 1;
			int k = max_length - 1;

			while (j >= 0) {
				result.numbers[k] = this->numbers[i] - x.numbers[j];
				i--; j--; k--;
			}

			while (i >= 0) {
				result.numbers[k] = this->numbers[i];
				i--; k--;
			}

			for (int i = max_length - 1; i > 0; i--) {
				if (result.numbers[i] < 0) {
					result.numbers[i - 1] -= 1;
					result.numbers[i] += 10;
				}
			}
		}
	}

	result.remove_leading_zeros();

	if (result.is_zero()) {
		result.sign = 1;
	}

	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {

	int max_length = this->length + x.length;
	LongNumber result(max_length, (this->sign == x.sign));

	for (int i = this->length - 1; i >= 0; i--) {
		for (int j = x.length - 1; j >= 0; j--) {
			result.numbers[i + j + 1] += x.numbers[j] * this->numbers[i];
		}
	}

	for (int i = max_length - 1; i > 0; i--) {
		result.numbers[i - 1] += result.numbers[i] / 10;
		result.numbers[i] %= 10;
	}

	result.remove_leading_zeros();
	return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	if (x.is_zero()) {
		return LongNumber();
	}

	LongNumber dividend = *this;
	LongNumber divisor = x;
	dividend.sign = 1;
	divisor.sign = 1;

	if (dividend < divisor) {
		return LongNumber();
	}

	LongNumber result;
	LongNumber remainder;

	for (int pos = 0; pos < dividend.length; pos++) {
		remainder = remainder * 10;
		remainder = remainder + LongNumber(dividend.numbers[pos]);
		remainder.remove_leading_zeros();

		int digit = 0;
		while (!(remainder < divisor)) {
			remainder = remainder - divisor;
			digit++;
		}

		result = result * 10;
		result = result + digit;
	}

	if (this->is_negative() and (result * divisor != dividend)) {
		result = result + 1;
	}

	if (!result.is_zero()) {
		result.sign = (this->sign == x.sign);
	}

	result.remove_leading_zeros();
	return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	return *this - (x * (*this / x));
}

bool LongNumber::is_negative() const noexcept {
	return this->sign == 0 and !is_zero();
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int length = 0;

	while (str[length] != '\0') {
		length += 1;
	}

	if (str[0] == '+' or str[0] == '-') {
		length -= 1;
	}
	return length;
}

void LongNumber::remove_leading_zeros() noexcept {
	if (this->length <= 1) {
		if (this->length == 1 and this->numbers[0] == 0) {
			this->sign = 1;
		}
		if (this->length == 1 && this->numbers[0] == 0) {
			this->sign = 1;
		}
	}

	int start = 0;

	while (start < this->length - 1 and this->numbers[start] == 0) {
		start++;
	}

	if (start > 0) {
		for (int i = 0; i < this->length - start; i++) {
			this->numbers[i] = this->numbers[start + i];
		}
		this->length -= start;

		if (this->length == 1 and this->numbers[0] == 0) {
			this->sign = 1;
		}
	}
}

bool LongNumber::is_zero() const noexcept {
	return (this->length == 1 and this->numbers[0] == 0);
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace drw {
	std::ostream& operator<<(std::ostream& os, const LongNumber& x) {
		if (x.sign == 0) os << '-';
		for (int i = 0; i < x.length; i++) {
			os << x.numbers[i];
		}
		return os;
	}
}
