/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:10:38 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/05 18:14:30 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl
{
    private:
        void (Harl::*probs[4])();
        void debug (void);
        void info (void);
        void warning (void);
        void error (void);
    public:
        void complain(std::string level);
        Harl();
        ~Harl();
};

#endif