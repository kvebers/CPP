
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data *data = new Data;

	data->serializeDouble = 1.0;
	data->serializeInt = 2;
	std::cout << "Before Modification" << std::endl;
	std::cout << "Double value : " << data->serializeDouble << std::endl;
	std::cout << "Int value : " << data->serializeInt << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	Data *deserializedData = Serializer::deserialize(ptr);

	std::cout << "After Modification" << std::endl;
	std::cout << "Double value : " << deserializedData->serializeDouble << std::endl;
	std::cout << "Int value : " << deserializedData->serializeInt << std::endl;

	std::cout << ptr << std::endl << Serializer::serialize(deserializedData) << std::endl;

	delete data;
	// system("leaks finally_done_with_irc");
}