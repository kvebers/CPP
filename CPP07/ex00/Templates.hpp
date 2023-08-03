#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename MAX>
MAX max(MAX a, MAX b) {
	return (b > a) ? b : a;
}

template <typename MIN>
MIN min(MIN a, MIN b) {
	return (b < a) ? b : a;
}

template <typename SWAP>
void swap(SWAP &a, SWAP &b) {
	SWAP tempSwap = a;
	a = b;
	b = tempSwap;
}

#endif