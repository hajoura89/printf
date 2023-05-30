# DESCRIPTION
Team project

# PROTOTYPE
int _printf(const char *format, ...);

# TASKS
## _0. I'M NOT GOING ANYWHERE. YOU CAN PRINT THAT WHEREVER YOU WANT TO. I'M HERE AND I'M A SPUR FOR LIFE_
	Write a function that produces output according to format.
⁃	c : converts input into a character
⁃	s : converts input into a string
⁃	% : converts input into a percentage
## _1. EDUCATION IS WHEN YOU READ THE FINE PRINT. EXPERIENCE IS WHAT YOU GET IF YOU DON'T_
	Handle the following conversion specifiers:
⁃	d : converts input into a base 10 integer
⁃	i : converts input into an integer
## _2. WITH A FACE LIKE MINE, I DO BETTER IN PRINT_
	Handle the following conversion specifiers:
⁃	b : the unsigned int argument is converted to binary
## _3. WHAT ONE HAS NOT EXPERIENCED, ONE WILL NEVER UNDERSTAND IN PRINT_
	Handle the following conversion specifiers:
⁃	u : converts the input into an unsigned integer
⁃	o : converts the input into an octal number
⁃	x : converts the input into a hexadecimal number
⁃	X : converts the input into a hexadecimal number with capital letters
## _4. NOTHING IN FINE PRINT IS EVER GOOD NEWS_
	Use a local buffer of 1024 chars in order to call write as little as possible.
## _5. MY WEAKNESS IS WEARING TOO MUCH LEOPARD PRINT_
	Handle the following custom conversion specifier:
⁃	S : prints the string
⁃	Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
## _6. HOW IS THE WORLD RULED AND LED TO WAR? DIPLOMATS LIE TO JOURNALISTS AND BELIEVE THESE LIES WHEN THEY SEE THEM IN PRINT_
	Handle the following conversion specifier:
⁃	p : int input is converted to a pointer address
## _7. THE BIG PRINT GIVES AND THE SMALL PRINT TAKES AWAY_
	Handle the following flag characters for non-custom conversion specifiers:
⁃	+ : adds a + in front of signed positive numbers and a - in front of signed negative numbers
⁃	space : same as +, but adds a space (is overwritten by +)
⁃	# : adds a 0 in front of octal conversions that don't begin with one, and a 0x or 0X for x or X conversions
## _8. SARCASM IS LOST IN PRINT_
	Handle the following length modifiers for non-custom conversion specifiers:
⁃	l : converts d, i, u, o, x, X conversions in short signed or unsigned ints
⁃	h : converts d, i, u, o, x, X conversions in long signed or unsigned ints
## _9. PRINT SOME MONEY AND GIVE IT TO US FOR THE RAIN FORESTS_
	Handle the field width for non-custom conversion specifiers.
## _10. THE NEGATIVE IS THE EQUIVALENT OF THE COMPOSER'S SCORE, AND THE PRINT THE PERFORMANCE_
	Handle the precision for non-custom conversion specifiers.
## _11. IT'S DEPRESSING WHEN YOU'RE STILL AROUND AND YOUR ALBUMS ARE OUT OF PRINT_
	Handle the 0 flag character for non-custom conversion specifiers.
## _12. EVERY TIME THAT I WANTED TO GIVE UP, IF I SAW AN INTERESTING TEXTILE, PRINT WHAT EVER, SUDDENLY I WOULD SEE A COLLECTION_
	Handle the - flag character for non-custom conversion specifiers.
## _13. PRINT IS THE SHARPEST AND THE STRONGEST WEAPON OF OUR PARTY_
	Handle the following custom conversion specifier:
⁃	r : prints the reversed string
## _14. THE FLOOD OF PRINT HAS TURNED READING INTO A PROCESS OF GULPING RATHER THAN SAVORING_
	Handle the following custom conversion specifier:
	R : prints the rot13'ed string
## _15. * _
	All the above options work well together.
