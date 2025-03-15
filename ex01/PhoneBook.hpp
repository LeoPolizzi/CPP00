/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpolizzi <lpolizzi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:59:34 by lpolizzi          #+#    #+#             */
/*   Updated: 2025/03/15 14:26:06 by lpolizzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <string>

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _index;
	bool _is_full;

  public:
	PhoneBook();
	~PhoneBook();

	void set_information();
	void get_information()const;
	void show_instruction();
};

#endif
