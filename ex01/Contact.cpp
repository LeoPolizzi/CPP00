/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:30:17 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/15 14:31:14 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::_fields[5] = {"First Name", "Last Name", "Nickname",
	"Phone Number", "Darkest Secret"};

Contact::Contact(void)
{
	std::cout << "Contact constructor called." << std::endl;
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->_informations[i] = std::string();
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called." << std::endl;
}

void Contact::set_informations(void)
{
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "Please enter the contact's " << Contact::_fields[i] << ":" << std::endl;
		while (!(std::getline(std::cin, this->_informations[i]))
			|| !this->_informations[i].length())
		{
			if (std::cin.eof())
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (!this->_informations[i].length())
			{
				this->_informations[i].clear();
				std::cout << "Empty contact information not allowed." << std::endl;
				std::cout << "Please enter the contact's " << Contact::_fields[i] << ":" << std::endl;
			}
		}
	}
	std::cout << "Contact successfully added." << std::endl;
}

void Contact::get_informations(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->_informations[i].length() > 10)
			std::cout << this->_informations[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_informations[i];
	}
	std::cout << "|" << std::endl;
}
