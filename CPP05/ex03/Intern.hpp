/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:34:42 by kvebers           #+#    #+#             */
/*   Updated: 2023/06/28 15:25:08 by kvebers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    public:
    //ORTHIOOX
    Intern();
    Intern(const Intern &idk);
    ~Intern();
    Intern &operator=(const Intern &idk);
    //function
    AForm *makeForm(const std::string& Name, const std::string& target) const;
    private:
    
};

#endif