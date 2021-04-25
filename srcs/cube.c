#include "./rt.h"

// double	plan_slice(t_obj *pln, double t)
// {
// 	if (dot(moins(pln->pos_slice, pln->hit), pln->slice) <= 0.0)
// 		return (-1);
// 	return (t);
// }

t_sol   slice_it_four_times(t_obj *plane, t_ray ray, double size)
{
    t_vect      template;
    // t_4vects    slicers;
    t_sol       sol;

    // template = sorting(plane->direction);
    // slicers = slicer_maker(template);
    sol.tmin = planiter(&plane, ray);
    // if (sol != -1 && !slice_it(plane, size, slicers))
    //     sol = -1;
    return (sol);
}

t_obj   cube_sides(t_vect plane_direction, t_obj *cube, t_ray ray)
{
    t_obj   plane;

    plane.v = plane_direction;
    plane.center = plus(multi(plane_direction, cube->size), cube->center);
    plane.size = 0;
    plane.slice = (t_vect){0, 0, 0};
    plane.sol = slice_it_four_times(&plane, ray, cube->size);
    return (plane);
}

void    init_cube(t_obj plane, t_obj *cube, t_sol *closest)
{
    cube->v = plane.v;
    cube->hit = plane.hit;
    cube->normal = plane.normal;
    cube->t = plane.t;
    closest->tmin = plane.sol.tmin;
}

void			init_sides(t_xyz	*sides)
{
	(*sides).x = (t_vect){1, 0, 0};
	(*sides).y = (t_vect){0, 1, 0};
	(*sides).z = (t_vect){0, 0, 1};
}

double			cubeintr(t_obj **cube, t_ray ray)
{
    t_obj   plane;
    t_sol   min;
	t_xyz	side;

    min.tmin = -1;
	init_sides(&side);
    plane = cube_sides(side.y, *cube, ray);
    if (min.tmin == -1 || min.tmin > plane.sol.tmin)
        init_cube(plane, *cube, &min);
    plane = cube_sides(multi(side.y, -1), *cube, ray);
    if (min.tmin == -1 || (min.tmin > plane.sol.tmin && plane.sol.tmin != -1))
        init_cube(plane, *cube, &min);
    plane = cube_sides(side.x, *cube, ray);
    if (min.tmin == -1 || (min.tmin > plane.sol.tmin && plane.sol.tmin != -1))
        init_cube(plane, *cube, &min);
    plane = cube_sides(multi(side.x, -1), *cube, ray);
    if (min.tmin == -1 || (min.tmin > plane.sol.tmin && plane.sol.tmin != -1))
        init_cube(plane, *cube, &min);
    plane = cube_sides(side.z, *cube, ray);
    if (min.tmin == -1 || (min.tmin > plane.sol.tmin && plane.sol.tmin != -1))
        init_cube(plane, *cube, &min);
    plane = cube_sides(multi(side.z, -1), *cube, ray);
    if (min.tmin == -1 || (min.tmin > plane.sol.tmin && plane.sol.tmin != -1))
        init_cube(plane, *cube, &min);
    return (min.tmin);
}