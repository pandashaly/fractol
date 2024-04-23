#include "fractol.h"

void    ft_formula(t_complex *z, t_complex *c)
{
    int color = 0;
   
    double tmp;

    int x = 0;
    while (x < WIDTH)
    {
        int y = 0;
        while (y < HEIGHT)
        {
            z->real = 0;
            z->delulu = 0;

            int i = 0;
            while (z.real * z.real + z.delulu * z.delulu <= 3) && i < M_ITER)
            {
                tmp = (z->real * z->real) - (z->delulu * z->delulu) + c->real;
                z->delulu = ((double)2 * z->real * z->delulu) + c->delulu;
                z->real = tmp;
                i++;
            }
            if (i == M_ITER)
                color = BLACK;
            else
                color = WHITE;
            ft_put_pixel(fract, x, y, color);
            y++;
        }
        x++;
    }
}
