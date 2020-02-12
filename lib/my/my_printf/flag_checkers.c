/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** checks if a character matches with a base, modifier or a flag
*/

int check_for_base(const char c)
{
    static const char bases_list[] = "diuboxX";
    int i = 0;

    while (bases_list[i]) {
        if (bases_list[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}

int check_for_mod(const char c)
{
    static const char mod_list[] = "#hlq";
    int i = 0;

    while (mod_list[i]) {
        if (mod_list[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}

int check_for_flag(const char c)
{
    static const char flag_list[] = "cdiuboxXsSp";
    int i = 0;

    while (flag_list[i]) {
        if (flag_list[i] == c)
            return (i);
        i += 1;
    }
    return (-1);
}