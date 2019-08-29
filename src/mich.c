/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mich.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:05:23 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/29 20:27:23 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long int dim_count(void)
{
    long int dim;
    int x;
    
    x = 0;
    dim = 1;
    while (x < ITER)
	{
		dim *= 3;
		x++;
	}
    return(dim);
}

long int d_count(long int d, t_coord cd)
{
    while (d != 0)
	{
		if (((cd.px % (d * 3)) / d == 1 && (cd.py % (d * 3)) / d == 1))
            return(d);
		d = d / 3;
	}
    return(d);
}