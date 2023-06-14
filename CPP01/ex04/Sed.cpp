/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:48:02 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:46:33 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename, std::string string1, std::string string2)
	: _filename(filename), _string1(string1), _string2(string2) {
	return;
}

Sed::~Sed() {
	std::cout << "Wow I did this in the most overcomplicated way possible, but why you might ask, "
				 "I do not know I just love causing pain and missery to myself"
			  << std::endl;
	return;
}

void Sed::ProcessTheFile() {
	std::string line;
	long long p;

	std::ifstream inputFile(_filename);
	if (inputFile.fail()) {
		std::cerr << "Error while opening the input file" << std::endl;
		return;
	}
	std::string outFile = _filename + ".replace";
	std::ofstream outputFile(outFile);
	if (outputFile.fail()) {
		std::cerr << "Error when creating the output file" << std::endl;
		return;
	}
	while (std::getline(inputFile, line)) {
		p = line.find(_string1);
		while (p != std::string::npos) {
			line = line.substr(0, p) + _string2 + line.substr(p + _string1.length());
			p = line.find(_string1, p + _string2.length());
		}
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();
	return;
}