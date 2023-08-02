#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <sys/_types/_uintptr_t.h>
#include <sys/types.h>

#include "Data.hpp"

class Serializer {
   public:
	Serializer();
	~Serializer();
	Serializer &operator=(const Serializer &idk);
	Serializer(const Serializer &idk);
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif