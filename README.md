## hpsh - Stack-based Reverse Polish Notation Calculator
![version] ![license]

```hpsh``` is a minimal implementation of Entry RPN that recreates the feel of Helwitt-Packard RPN calculators.

A CLI-based RPN interpreter with an unlimited stack depth!

### Usage
Use ```hpsh``` just like you would a real RPN calculator. ```hpsh``` does not evaluate until you press **ENTER**.
```
Command:   | 8.33 ENTER | 4 ENTER | 5.2 - ENTER | * ENTER   |

Stack:     | 1: 8.33    | 2: 8.33 | 2: 8.33     | 1: -9.996 |
                        | 1: 4    | 1: -1.2     |
```
Entering values without a corresponding operator will push them to the stack.

For example, pressing ```32 14 27 19 / ENTER``` will produce
```
3: 32
2: 14
1: 1.42105
```
The result of all your commands is reflected on the stack, which is unlimited in depth.
The current state of the stack updates only when you press **ENTER**.
You can evaluate an arbitrary amount of values and operators all at once, but Entry RPN is much more intutive when you push values to the stack and use it to visualize your intermediate calculations.


### About RPN
RPN is a postfix notation. Instead of ```3 * 4``` you write ```3 4 *```.

RPN doesn't use parentheses to enforce operator precedence, instead, it forces the user to account for order of operations.
While it may seem backwards, it's actually quite intuitive for large equations. The stack allows you to visualize operations like you would on paper, letting you push nested values up into the stack until you need them.

This encourages the user to consciously break an equation down into smaller pieces and calculate them one at a time, pushing intermediate results to the stack and collapsing them to form a final answer.
```
Algebraic
sqrt( (8.33(4 - 5.2) / ((8.33 - 7.46)0.32)) / (4.3(3.15 - 2.75) - (1.71)(2.01)) )
= 4.57278428023

Entry RPN (E stands for ENTER, pushing a value to the stack without performing operations on it)
8.33 E 4 E 5.2 - * 8.33 E 7.46 - 0.32 * / 4.3 E 3.15 E 2.75 - * 1.71 E 2.01 * / sqrt
1: 4.57278428023
```
If you're having trouble visualizing RPN, try to imagine the way you do calculations on paper. 
The first number can be pushed to the stack, while the second number is paired with an operator to perform math.
That's all there is to RPN.
```
Algebraic     RPN       Paper      
3 * 4         3 ENTER   3
= 12          4 *       4 x
              1: 12     ----
                        12
```
For more information, see [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) on Wikipedia.

### Building
```git clone``` into this repository or grab the latest stable release as a zip or tarball from the [Releases](https://github.com/microsounds/hpsh/releases) tab.

Run ```make``` to build, or ```sudo make install``` if you want to install it to your system.

### Issues
Open an issue or pull request if you find any bugs.

### Copyright / License
```
hpsh - Stack-based Reverse Polish Notation Calculator
Copyright (C) 2016 microsounds <https://github.com/microsounds>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
```

[version]: https://img.shields.io/badge/version-v0.2.0-brightgreen.svg?style=flat)
[license]: https://img.shields.io/badge/license-GPLv3-red.svg?style=flat)
