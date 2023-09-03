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
#include "Point.hpp" // needed for Point class, Fixed class, <iostream>
#include <cstring>   // needed for strcmp()

#include "./MLX42/include/MLX42/MLX42.h" // needed as graphics library

#define HEIGHT 600 // Window Height
#define WIDTH  600 // Window Width

#define SLEEP_DURATION 2 // Interval between showing points and drawing triangle

bool bsp( Point const a, Point const b, Point const c, Point const point );

static inline int32_t get_rgba( int32_t r, int32_t g, int32_t b, int32_t a )
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static inline int rand_i_range( int min, int max )
{
	return min + (std::rand() % (max - min + 1));
}

static inline void print_err_and_exit(std::string message)
{
	std::cerr << message << std::endl;
	exit (EXIT_FAILURE);
}

static void key_hook( void *param )
{
	mlx_t* mlx = (mlx_t *) param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}
}

static void draw_bsp( mlx_image_t* image, Point& a, Point &b, Point& c )
{
	int32_t color_bg = get_rgba(176, 224, 230, 255);
	int32_t color_tri = get_rgba(255, 69, 0, 255);

	for (int y = 0;	y < HEIGHT;	++y)
	{
		for (int x = 0;	x < WIDTH; ++x)
		{
			Point pixel(x, y);
			if (bsp(a, b, c, pixel) == true)
			{
				mlx_put_pixel(image, x, y, color_tri);
			}
			else
			{
				mlx_put_pixel(image, x, y, color_bg);
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1 && argc != 2)
	{
		print_err_and_exit("Bad arguments: usage:  ./bsp || ./bsp r");
	}

	mlx_t*       mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Binary Space Partitioning", false);
	if (mlx == NULL)
	{
		print_err_and_exit("MLX init failure");
	}

	mlx_image_t* image;

	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (image == NULL)
	{
		print_err_and_exit("Image new failure");
	}

	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		print_err_and_exit("Image to window failure");
	}

	if (argc == 2 && strcmp(argv[1], "r") == 0)
	{
		Point a(rand_i_range(0, WIDTH), rand_i_range(0, WIDTH));
		Point b(rand_i_range(0, WIDTH), rand_i_range(0, WIDTH));
		Point c(rand_i_range(0, WIDTH), rand_i_range(0, WIDTH));

		draw_bsp(image, a, b, c);
	}
	else
	{
		Point a(50, 50);
		Point b(150, 150);
		Point c(600, 300);

		draw_bsp(image, a, b, c);
	}

	mlx_loop_hook(mlx, key_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
