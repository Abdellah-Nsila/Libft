/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:34:07 by znajdaou          #+#    #+#             */
/*   Updated: 2024/10/25 10:34:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int main()
{
	int ddd = 1;
	int* ptr;
	(*ptr) = 77;
	printf("1: %p,\n2: %i", ptr, *ptr);
}
