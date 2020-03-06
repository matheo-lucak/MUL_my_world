/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** A header for vector processings
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <SFML/System/Vector2.h>

#define vec2f(x, y) (sfVector2f){x, y}
#define vec2i(x, y) (sfVector2i){x, y}

//Returns the sum of vec1 and vec2.
sfVector2f vec_add(sfVector2f vec1, sfVector2f vec2);

//Returns the left of vec1 minus vec2.
sfVector2f vec_sub(sfVector2f vec1, sfVector2f vec2);

//Returns the product of vec1 by scalar coeff.
sfVector2f vec_mult(sfVector2f vec1, float coeff);

//Returns the quotient of vec1 by scalar coeff.
sfVector2f vec_div(sfVector2f vec1, float coeff);

//Returns the magnitude of vec1.
float vec_mag(sfVector2f vec1);

//Returns the normalised vector of vec1.
sfVector2f vec_norm(sfVector2f vec1);

//Returns vec1 given as parameter with limited values in x and y.
sfVector2f vec_lim(sfVector2f vec1, sfVector2f top_lim, sfVector2f bottom_lim);

#endif /* VECTOR_H_ */
