/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:25:12 by rjoella           #+#    #+#             */
/*   Updated: 2020/12/29 10:38:51 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int k = -12345 ;
	unsigned int l = -123;
	// int j = 1234;
	// int l = -1234;
	// int q = -1234;
	// int w = 17465;
	// int e = 17465;
	char *s = "asdfg";
	char *sd;
	int m;
	int n;
	m = ft_printf("|%-10%| %010.4d %15p %-10.13x %0*.2u\n", 23, s, 255, -10, -122);
	//n = printf("|%010%|\n");
	// m = ft_printf("|%-10.5d|\n", l);
	// n = printf("|%-10.5d|\n", l);
	//printf("my %d --- then %d\n", m, n);

	// while (1)
	// 	;
	return (0);
}
