#include "fractol.h"

void ft_init_burningship(t_fractol *fract)
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
            z.real = 0;
            z.delulu = 0;

            int i = ft_burningship(&z, &c);
            ft_draw(fract, x, y, i);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fract->mlx, fract->window, fract->img.img, 0, 0);
}

int  ft_burningship(t_complex *z, t_complex *c)
{
  int i = 0;
  while ((z->real * z->real + z->delulu * z->delulu <= 4) && i < M_ITER)
  {
    double tmp = z->real * z->real - z->delulu * z->delulu + c->real;
    z->delulu = fabs(2 * z->real * z->delulu) + c->delulu;
    z->real = tmp;
    i++;
  }
  return (i);
}
