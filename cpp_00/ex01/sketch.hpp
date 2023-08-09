
// General
//	user input only: [ADD], [SEARCH], [EXIT]
//	NO CONTAINERS!! (STD::STRING and STD::ARRAY are considered
//		Containers!!
//	cleaning up in separate functions and less files mb?
		/* use private instead of public if possible */
		/* should exit work in any state? */
		/* initialisation lists instead of hard coded assignments */

// ADD
//	one field at a time, no empty fields!
//	once all fields are done, add the contact to the phonebook

// SEARCH
//	display Contact as a list of 4 columns:
//		index
//		first_name
//		last_name
//		nickname
//	each column is 10 characters wide, separated by pipe
//	truncate if there is an overlap with an '.'
//	prompt again for no_index
//	if index is out of bounds, define relevant behavior (reloop)
// EXIT

// class Phonebook
//	8 Contacts
//	9th Contact will overwrite oldest one
//	no dynamic allocation
//	empty on startup
//	index

// class Contact
//	information stored:
//		first_name
//		last_name
//		nickname
//		phone number
//		darkest secret
//	no empty fields!

