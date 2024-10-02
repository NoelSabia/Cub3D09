/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel <noel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:37:23 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/02 17:27:04 by noel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    drawWall(t_mlx *mlx, int bottom_end_of_wall, int top_end_of_wall)
{
    static int  i; //static int, damit wir bei erneutem aufrufen die alte Value behalten
    int         x_start; //x-axis wo ich beginnen werde es zu zeichnen
    int         x_end; //x-axis wo ich enden werde
    
    x_start = i * WALL_SLICE_WIDTH; //hier kommt static int i ins spiel, da die value angepasst wird beispiel i(1) * WALL_SLICE = 16 beim zweiten durchlauf aber i(2) * WALL_SLICE = 32 usw.
    x_end = i * WALL_SLICE_WIDTH + WALL_SLICE_WIDTH; //dies ist das ende, setzt sich dadurch zusammen, dass 120 Rays ausgeschossen werden und ich den Screen in 120 abteile unterteilt habe.
    while (x_start <= x_end) //erster while loop fuer die x-axis
    {
        while (bottom_end_of_wall <= top_end_of_wall) //zweiter while loop fuer die y-axis
        {
            // printf("y: %d\n", bottom_end_of_wall); //debugging
            // printf("x: %d\n\n", x_start);    //debugging
            mlx_put_pixel(mlx->img, x_start, bottom_end_of_wall, 0x00ff00ff); //hier bekomme ich den segv, check das debugging aus, immer an den values x=953 und y=0 und ich verstehe nicht wieso
            bottom_end_of_wall++; //immer eins weiter in der y-axis
        }
        x_start++; //immer eins weiter in der x-axis
    }
    i++; //damit static int erhoeht wird
    if (i == 120) //wenn wir 120 rays ausgeschossen haben wollen wir ja wieder von links anfangen, deswegen wieder auf 0 zurueckgesetzt
        i = 0;
}

void     calculateWallHeight(t_mlx *mlx)
{
    int wall_height;
    int bottom_end; //bottom_end der wand also der groesste y-wert von dem wall_slice
    int top_end; //top_end der wand also der kleinste y-wert von dem wall_slice
    
    wall_height = (TILE_SIZE / mlx->ray->distance_to_w) * ((SCREEN_HEIGHT / 2) / tan(1.047197551 / 2));
    bottom_end = -wall_height / 2 + SCREEN_HEIGHT / 2;
    top_end = wall_height / 2 + SCREEN_HEIGHT / 2;
    if (bottom_end < 0) //safety massure
        bottom_end = 0;
    else if (top_end >= SCREEN_HEIGHT) //safety massure
        top_end = SCREEN_HEIGHT - 1;
    drawWall(mlx, bottom_end, top_end);
}
