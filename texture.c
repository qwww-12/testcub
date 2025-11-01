#include "cub3d.h"

//cfg.txt->no = mlx_load_png("path_to_north.png");
//cfg.txt->so = mlx_load_png("path_to_south.png");
//cfg.txt->we = mlx_load_png("path_to_west.png");
//cfg.txt->ea = mlx_load_png("path_to_east.png");



/*
** دالة بسيطة ترسم wall texture لكل جدار
** NO / SO / WE / EA فقط
** TILE_SIZE = 64
*/

void	draw_wall_texture(t_config *cfg, int x, int y)
{
	mlx_image_t	*img;

	img = NULL;

	if (!cfg || !cfg->txt || !cfg->map)
		return ;

	if (cfg->map[y][x] != '1')
		return ;

	/* اختيار texture حسب position في الخريطة */
	if (y == 0)
		img = cfg->txt->no;   /* North wall */
	else if (y == cfg->map_height - 1)
		img = cfg->txt->so;   /* South wall */
	else if (x == 0)
		img = cfg->txt->we;   /* West wall */
	else if (x == cfg->map_width - 1)
		img = cfg->txt->ea;   /* East wall */
	else
		img = cfg->txt->no;   /* default North */

	if (img)
		mlx_image_to_window(cfg->mlx, img, x * 64, y * 64);
}

/*
** دالة رئيسية لرسم جميع الجدران
** NO / SO / WE / EA فقط
*/
void	draw_all_walls(t_config *cfg)
{
	int	x;
	int	y;

	if (!cfg || !cfg->map)
		return ;

	y = 0;
	while (cfg->map[y])
	{
		x = 0;
		while (cfg->map[y][x])
		{
			draw_wall_texture(cfg, x, y);
			x++;
		}
		y++;
	}
}
