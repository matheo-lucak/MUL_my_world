/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_update
*/

#ifndef MAP_UPDATE_H_
#define MAP_UPDATE_H_

#include <SFML/System/Vector2.h>
#include <SFML/System/Vector3.h>

//Computes isometric projection of 3D point to 2D plane.
sfVector2f project_iso_point(const sfVector3f pos_3d, sfVector2i map_size,
                            sfVector2i angles);

//Updates map 2D by computing isometric coordinates of each point of the map.
void update_map_2d(map_formatter_t *terraformer);

#endif /* MAP_UPDATE_H_ */
