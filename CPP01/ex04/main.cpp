/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:54:25 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 16:00:13 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr<<"Wrong number of arguments" <<std::endl;
        return (0);
    }
    Sed sed(argv[1], argv[2], argv[3]);
    sed.ProcessTheFile();
    system("leaks replace_sed");
    return (0);
}