#include "TargetGenerator.hpp"

#include <cstddef>

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(TargetGenerator const &other) {
	size_t i;

	i = targets.size();
	while (i-- > 0) delete targets.at(i);

	targets.clear();

	i = 0;
	while (i++ < other.targets.size()) targets.push_back(other.targets.at(i)->clone());
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other) {
	if (this != &other) {
		size_t i = targets.size();

		while (i-- > 0) delete targets.at(i);
		targets.clear();

		i = 0;
		while (i++ < other.targets.size()) targets.push_back(other.targets.at(i)->clone());
	}
	return *this;
}

TargetGenerator::~TargetGenerator() {
	size_t i;

	i = targets.size();
	while (i-- > 0) delete targets.at(i);

	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target) {
	size_t i;

	i = targets.size();
	while (i-- > 0) {
		if (targets.at(i)->getType().compare(target->getType()) == 0) return;
	}

	targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(std::string const &targetName) {
	size_t i;

	i = targets.size();
	while (i-- > 0) {
		if (targets.at(i)->getType().compare(targetName) == 0) {
			delete targets.at(i);
			targets.erase(targets.begin() + i);
			return;
		}
	}
}

ATarget *TargetGenerator::createTarget(std::string const &targetName) {
	size_t i;

	i = targets.size();
	while (i-- > 0) {
		if (targets.at(i)->getType().compare(targetName) == 0) return (targets.at(i));
	}
	return NULL;
}
