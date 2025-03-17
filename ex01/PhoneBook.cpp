/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:06:04 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/15 14:31:03 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _is_full(false)
{
	std::cout << "PhoneBook constructor called." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called." << std::endl;
}

void PhoneBook::set_information()
{
	std::string input;
	if (!this->_is_full)
	{
		std::cout << "Please enter the contact's information for contact #" << this->_index
			+ 1 << std::endl;
		this->_contacts[this->_index].set_informations();
		this->_index++;
		if (this->_index == 8)
			this->_is_full = true;
	}
	else
	{
		std::cout << "Phonebook is full. Oldest contact is goind to be deleted if you wish to proceed." << std::endl;
		std::cout << "Do you wish to proceed? (y/n)" << std::endl;
		while (!(std::getline(std::cin, input)) || (input.compare("y")
				&& input.compare("n")))
		{
			if (std::cin.eof())
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else
			{
				std::cout << "Invalid input." << std::endl;
				std::cout << "Do you wish to proceed? (y/n)" << std::endl;
			}
		}
		if (!input.compare("y"))
		{
			for (int i = 0; i < 7; i++)
				this->_contacts[i] = this->_contacts[i + 1];
			std::cout << "Please enter the contact's information for contact #8" << std::endl;
			this->_contacts[7].set_informations();
		}
		else
			std::cout << "Back to main menu." << std::endl;
	}
}

void PhoneBook::get_information() const
{
	int index;
	if (!this->_index)
		std::cout << "Phonebook is empty. Please add at least one contact before searching." << std::endl;
	else
	{
		std::string input;
		std::cout << "Please enter the index of the contact you wish to display (1-8). (0 to quit searching)\nIndex: ";
		while (!(std::getline(std::cin, input)) || input.length() > 1
			|| input.compare("0") < 0 || input.compare("8") > 0
			|| (std::atoi(input.c_str()) - 1 >= this->_index
				&& this->_is_full == false))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
				std::exit(0);
			}
			else if (input.length() > 1 || input.compare("0") < 0
				|| input.compare("8") > 0)
			{
				std::cin.clear();
				std::cout << "Only digits in range of 1 to 8 are allowed.\n";
				std::cout << "Please enter the index of the contact you wish to display (1-8). (0 to quit searching)\nIndex: ";
			}
			else if (std::atoi(input.c_str()) - 1 >= this->_index
				&& this->_is_full == false)
			{
				std::cout << "You only have " << this->_index << " Contacts saved." << std::endl;
				std::cin.clear();
				std::cout << "Please enter the index of the contact you wish to display (1-8). (0 to quit searching)\nIndex: ";
			}
		}
		index = std::atoi(input.c_str());
		if (index > 0)
		{
			std::cout << "|-------------------------------------------|" << std::endl;
			std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			this->_contacts[index - 1].get_informations(index);
			std::cout << "|-------------------------------------------|" << std::endl;
		}
		else
			std::cout << "Back to main menu." << std::endl;
	}
}

void PhoneBook::show_instruction()
{
	std::cout << "Please enter one of the following commands:\nADD\nSEARCH\nEXIT" << std::endl;
}
