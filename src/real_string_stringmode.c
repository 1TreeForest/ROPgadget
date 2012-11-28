/*
** RopGadget - Release v3.4.2
** Jonathan Salwan - http://twitter.com/JonathanSalwan
** Allan Wirth - http://allanwirth.com/
** http://shell-storm.org
** 2012-11-11
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include "ropgadget.h"

void print_real_string(char *str)
{
  size_t l;
  size_t i;
  l = strlen(stringmode.string);

  for (i = 0; i < l; i++)
    fprintf(stdout, (str[i] >= 0x20 && str[i] <= 0x7e)?"%c":"\\x%.2x", str[i]);
}

char *real_string_stringmode(char *base_string, unsigned char *data)
{
  char *real_string;
  char *i;

  real_string = xmalloc((strlen(base_string) + 1) * sizeof(char));
  strcpy(real_string, base_string);

  /* Loop through ?s and set them to the same index in data */
  while((i = strchr(real_string, '?')) != NULL)
    *i = data[(i - real_string)];

  return real_string;
}
