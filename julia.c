#include "fractol.h"

void ft_init_julia(t_fractol *fract, double julia_r, double julia_i)
{
    t_complex z;
    t_complex c;

    int x = 0;
    while (x < WIDTH)
    {
        int y = 0;
        while (y < HEIGHT)
        {
            c.real = julia_r;
            c.delulu = julia_i;
            z.real = (double)x / WIDTH * (MAX_REAL - MIN_REAL) + MIN_REAL;
            z.delulu = (double)y / HEIGHT * (MAX_IMAGINARY - MIN_IMAGINARY) + MIN_IMAGINARY;

            int i = ft_julia(&z, &c);
            ft_draw(fract, x, y, i);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

int  ft_julia(t_complex *z, t_complex *c)
{
  int i = 0;
  while ((z->real * z->real + z->delulu * z->delulu <= 4) && i < M_ITER)
  {
    double tmp = z->real * z->real - z->delulu * z->delulu + c->real;
    z->delulu = 2 * z->real * z->delulu + c->delulu;
    z->real = tmp;
    i++;
  }
  return (i);
}
