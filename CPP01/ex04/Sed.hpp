/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:02:02 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/14 08:46:36 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <string>

class Sed {
   private:
	std::string _filename;
	std::string _string1;
	std::string _string2;

   public:
	Sed(std::string filename, std::string string1, std::string string2);
	~Sed();
	void ProcessTheFile();
};

#endif