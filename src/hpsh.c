#include <stdio.h>

#include "stack.h"
#include "interpreter.h"

#define INPUT_BUF 1000

/*
 *  hpsh - Stack-based Reverse Polish Notation Calculator
 *  Copyright (C) 2016 microsounds <https://github.com/microsounds>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Open an issue on Github if you encounter any problems.
 * https://github.com/microsounds/hpsh
 *
 * For building, installation and usage information, see README.md.
 */

struct {
	const char *name;
	const char *ver;
	const char *date;
	const char *author;
	const char *license;
} a = {
	.name = "hpsh",
	.ver = "0.3.1",
	.date = "2016",
	.author = "microsounds",
	.license = "GPLv3+",
};

int main(int argc, char **argv)
{
	list_t stack;
	stack_init(&stack);
	fprintf(stderr, "%s %s -- (C) %s %s, %s\n",
	        a.name, a.ver, a.date, a.author, a.license);
	fprintf(stderr, "Type 'help' for help and 'quit' to quit.\n");
	while (1)
	{
		char input[INPUT_BUF];
		fprintf(stdout, "> ");
		fgets(input, INPUT_BUF, stdin);
		lexer(input, &stack);
		stack_display(&stack);
	}
	stack_destroy(&stack);
	return 0;
}
