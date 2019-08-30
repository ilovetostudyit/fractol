/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mich.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:05:23 by ehaggon           #+#    #+#             */
/*   Updated: 2019/08/30 13:09:30 by ehaggon          ###   ########.fr       */
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

int mand_count(t_pnum p)
{
    int i;
    t_fract		mn;

    mn.newre = 0;
	mn.newim = 0;
    i = 0;
    while (i < ITER)
	{
		mn.oldre = mn.newre;
		mn.oldim = mn.newim;
		mn.newre = mn.oldre * mn.oldre - mn.oldim * mn.oldim + p.pr;
		mn.newim = 2 * mn.oldre * mn.oldim + p.pi;
		if ((mn.newre * mn.newre + mn.newim * mn.newim) > 4)
			return(i);
		i++;
	}
    return(i);
}

int julia_count(t_pnum p)
{
	int i;
	t_fract		mn;

	i = 0;
	mn.newre = p.pr;
	mn.newim = p.pi;
	while (i < ITER)
	{
		mn.oldre = mn.newre;
		mn.oldim = mn.newim;
		mn.newre = mn.oldre * mn.oldre - mn.oldim * mn.oldim + cre;
		mn.newim = 2 * mn.oldre * mn.oldim + cim;
		if ((mn.newre * mn.newre + mn.newim * mn.newim) > 4)
			return(i);
		i++;
	}
	return(0);
}