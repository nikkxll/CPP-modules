/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:25:53 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/17 12:30:30 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end)
{
	if (std::distance(begin, end) + _set.size() > _limit)
	{
		throw std::out_of_range("Adding this range would exceed set's capacity");
	}
	_set.insert(begin, end);
}
