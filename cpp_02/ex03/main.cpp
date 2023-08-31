// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>   // needed for MACROS
#include <iostream>  // needed for std::cout, std::endl
#include "Point.hpp" // needed for Point

#include "./MLX42/include/MLX42/MLX42.h"   // graphics library

#define HEIGHT 600
#define WIDTH  600

Point a(250, 130);
Point b(5, 540);
Point c(50,50);
Point point(400, 30);

bool bsp( Point const a, Point const b, Point const c, Point const point );

int32_t get_rgba( int32_t r, int32_t g, int32_t b, int32_t a )
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void draw_background( mlx_image_t* image )
{
	int32_t color_bg = get_rgba(176, 224, 230, 255);
	
	for (size_t y = 0; y < HEIGHT; ++y)
	{
		for (size_t x = 0; x < WIDTH; ++x)
		{
			mlx_put_pixel(image, x, y, color_bg);
		}
	}
}

void key_hook( void *param )
{
	mlx_t* mlx = (mlx_t *) param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}
}

void draw_point( mlx_image_t* image, Point& p_print, int32_t color)
{

	std::cout << p_print << std::endl;

	for (size_t y = (size_t) p_print.get_y() - 5;
			y < (size_t) p_print.get_y() + 5 && y < HEIGHT;
			++y)
	{
		for (size_t x = p_print.get_x() - 5;
				x < p_print.get_x() + 5 && x < WIDTH;
				++x)
		{
			mlx_put_pixel(image, x, y, color);
		}
	}
}

int	main( void )
{
	mlx_t*       mlx;
	mlx_image_t* image;

	int32_t color_tri = get_rgba(255, 69, 0, 255);
	int32_t color_p = get_rgba(0, 0, 0, 255);

	mlx = mlx_init(WIDTH, HEIGHT, "Binary Space Partitioning", false);

	image = mlx_new_image(mlx, WIDTH, HEIGHT);

	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		std::cout << "image to window failure" << std::endl;
	}

	draw_background(image);

	draw_point(image, a, color_tri);
	draw_point(image, b, color_tri);
	draw_point(image, c, color_tri);
	draw_point(image, point, color_p);

	if (bsp (a, b, c, point) == true)
	{
		std::cout << "true!" << std::endl;
	}
	else
	{
		std::cout << "false!" << std::endl;
	}

	mlx_loop_hook(mlx, key_hook, mlx);
	
	mlx_loop(mlx);
	
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
