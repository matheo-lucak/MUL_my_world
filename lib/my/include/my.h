/*
** EPITECH PROJECT, 2019
** library
** File description:
** header for libmy
*/

#ifndef MY_H_

#define MY_H_

#include <stddef.h>
//Puts a char onto the stdout.
//
//Returns 0 if it has been written.
//Returns 84 otherwise.
int my_putchar(const char c);

//Puts a string onto the stdout.
//
//Returns 0 if it has been entirely written.
//Returns 84 otherwise.
int my_putstr(const char *str);

//Gets an int from a string.
//
//Returns 0 if the contained int is > MAX_INT or < MIN_INT
//Returns 0 if the string is NULL
//Returns nothing as such as a number has been found into the string
//before finding a none number character
int my_getnbr(const char *str);

//Checks if a char is an alphabetical letter.
//
//Returns 1 if it is.
//Returns 0 otherwise.
int my_isalpha(const char c);

//Checks if a char is a digit.
//
//Returns 1 if it is.
//Returns 0 otherwise.
int my_isnum(const char c);

//Checks whether a char is a digit or an alphabetical letter.
//
//Returns 1 if it is.
//Returns 0 otherwise.
int my_isalphanum(const char c);

//Checks whether a string only contains digits or
//alphabetical letters as char's.
//
//Returns 1 if it is.
//Returns 0 otherwise.
int my_str_is_alphanum(const char *str);

//Checks whether a string only contains digits
//
//Returns 1 if it is.
//Returns 0 otherwise.
int my_str_is_num(const char *str);

//Prints onto the stdout with custom flags to print variables.
//
//%c -> prints a char.
//%d -> prints an int (base 10).
//%i -> prints an int (base 10).
//%b -> prints an int (base 2).
//%o -> prints an int (base 8).
//%x -> prints an int (base 16 -> abcdef in lowercases).
//%X -> prints an int (base 16 -> abcdef in uppercases).
//%s -> prints a string.
//%S -> prints a string (non-printable's are printed in a \000
//form with 000 the octal value in the ascii table of the char).
//%p -> prints the address of a pointer in this form:
//"0x0..." with 0... being the lowercased hexa form of the address.
//
//%ld -> prints a long int (base 10).
//%li -> prints a long int (base 10).
//%lld -> prints a long long int (base 10).
//%qd -> prints a long long int (base 10).
//%qi -> prints a long long int (base 10).
//
//%lu -> prints an unsigned long int (base 10).
//%llu -> prints an unsigned long long int (base 10).
//%qu -> prints an unsigned long long int (base 10).
//
//%hd -> prints a short int (base 10).
//%hi -> prints a short int (base 10).
//%hu -> prints an unsigned short int (base 10).
//%hhd -> prints a short short int (base 10).
//%hhi -> prints a short short int (base 10).
//%hhu -> prints a unsigned short short int (base 10).
//
//%#d -> prints an int (base 10).
//%#i -> prints an int (base 10).
//%#u -> prints an int (base 10).
//%#o -> prints an int (base 8) -> If the octal number isn't 0
//Prints a 0 before it.
//%#x -> prints an int (base 16 -> abcdef in lowercases) ->
//Prints 0x before it.
//%#X -> prints an int (base 16 -> abcdef in uppercases) ->
//Prints 0x before it.
int my_printf(char const *input, ...);

//Gets a line from a file, gets the next one at each function call
//without the \n at the end.
//
//Returns NULL if:
//- fd = -1.
//- mallocs failed.
//- nothing is left to read.
char *get_next_line(const int fd);

//Puts an int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr(int nb, const char *base);

//Puts an unsigned int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr_u(unsigned int nb, const char *base);

//Puts a short int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr_s(short int nb, const char *base);

//Puts an unsigned short int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr_su(unsigned short int nb, const char *base);

//Puts a long int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr_l(long int nb, const char *base);

//Puts an unsigned long int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr_lu(unsigned long int nb, const char *base);

//Puts a long long int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr_ll(long long int nb, const char *base);

//Puts an unsigned long long int onto the stdout, considering its based.
//
//If your chosen base if decimal, for instance,
//base = "0123456789".
void my_put_nbr_llu(unsigned long long int nb, const char *base);

//Returns the size of an int.
//
//Example: the size of '2' is 1, the size of '2134" is 4.
int my_int_size(int nb);

//Returns an allocated char * filled with the ascii representation of
//the given number as parameter
char *my_int_to_str(int nb);

//Gets the size of a string.
//
//Returns -1 if string is NULL.
int my_strlen(const char *str);

//Gets the size of an array.
//
//Returns 0 if array is NULL.
int my_arrlen(void **array);

int my_strnlen(const char *str, const int n);
int my_strlen_char(const char *str, const char c);
int my_strlen_cmpstr(const char *str, const char cmp[]);

void my_show_arr(char **array);
int my_arrcmp(char **first, char **second);
char **my_arrdup(const char * const *template);
char **my_append_to_array(char **array, char *str, const int freer);
void my_free_arr(char **array);

char *my_strdup(const char *template);
char *my_strndup(const char *template, int n);
char *my_strdup_char(const char *template, const char c);
char *my_strdup_cmpstr(const char *template, const char cmp[]);
int my_strcmp(const char *first, const char *second, const int splitter);
int my_strncmp(const char *first, char const *second, const unsigned int n);

void my_memset(char *str, const char c, const int len);
void *my_memcpy(void *dest, const void *src, size_t n);

char *my_strcat(const char *core, const char *to_append);
char *my_strcpy(char *dest, char const *src);
char **my_str_to_word_array(char *sentence, const char splitter[],
                            const unsigned int freer);

//Returns a radian float considering a degree.
float my_radians(const int degrees);

//Checks if a char matches with at least another char in a string.
//
//Example: str = " \t", c = '\t'; -> Returns 1 because '\t' is in str.
//
//Returns 1 if is matches.
//Returns 0 otherwise.
int find_char_in_str(const char *str, const char c);

#endif /* MY_H_ */