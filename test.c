/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:46:47 by jingchen          #+#    #+#             */
/*   Updated: 2022/11/30 16:49:47 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void testFunc(int sum)
{
	static int i = 0;

	i+=sum;
	printf("%d\n", i);
}

int main(void)
{
	testFunc(5);
	testFunc(40);
	return 0;
}