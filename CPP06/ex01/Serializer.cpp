#include "Serializer.hpp"

#include <sys/_types/_uintptr_t.h>

#include "Data.hpp"

// ORTHODOX
Serializer::Serializer() { std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl; }
Serializer::~Serializer() { std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl; }

Serializer &Serializer::operator=(const Serializer &idk) {
	if (this != &idk) return *this;
	std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl;
	return *this;
}

Serializer::Serializer(const Serializer &idk) {
	std::cout << "IDK wHY WE NEED THIS IN THIS EXECERSISE" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data *Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }
