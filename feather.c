#include "fractol.h"

void ft_init_feather(t_fractol *fract, double fx, double fy)
{
    t_complex z;
    t_complex c;

    int x = 0;
    while (x < WIDTH)
    {
        int y = 0;
        while (y < HEIGHT)
        {
            c.real = (double)x / WIDTH * (MAX_REAL - MIN_REAL) + MIN_REAL;
            c.delulu = (double)y / HEIGHT * (MAX_IMAGINARY - MIN_IMAGINARY) + MIN_IMAGINARY;
            z.real = c.real;
            z.delulu = c.delulu;

            int i = ft_feather(&z, fx, fy);
            ft_draw(fract, x, y, i);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

int  ft_feather(t_complex *z, double fx, double fy)
{
  int i = 0;
  while ((z->real * z->real + z->delulu * z->delulu <= 4) && i < M_ITER)
  {
    double x2 = z->real * z->real;
    double y2 = z->delulu * z->delulu;
    double x3 = z->real * x2;
    double y3 = z->delulu * y2;
    double denom = 1 + x2 + y2;

    z->real = (x3 - 3 * z->real * y2) / denom + fx;
    z->delulu = (y3 - 3 * z->delulu * x2) / denom + fy;

    i++;
  }
  return (i);
}
