/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:03:38 by dbirge-c          #+#    #+#             */
/*   Updated: 2017/11/13 14:05:05 by dbirge-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int n)
{
	int	result;

	result = 0;
	if (n < 0)
		return (0);
	while (result * result < n && result < 46340)
		result++;
	if (result * result == n)
		return (result);
	else
		return (0);
}
