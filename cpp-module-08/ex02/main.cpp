/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:21:54 by dnikifor          #+#    #+#             */
/*   Updated: 2024/08/19 14:49:53 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>
#include <iostream>

int main(void)
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		MutantStack<double> doubleStack;
		doubleStack.push(1.1);
		doubleStack.push(2.2);
		doubleStack.pop();
		std::cout << "Top element: " << doubleStack.top() << std::endl;
		doubleStack.push(3.3);
		doubleStack.push(12);
		MutantStack<double>::iterator it = doubleStack.begin();
		while (it != doubleStack.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<double> d(doubleStack);
		std::cout << d.top() << std::endl;
		std::cout << d.size() << std::endl;
	}
	{
		MutantStack<std::string> strStack;
		strStack.push("Hello");
		strStack.push("world");
		strStack.pop();
		std::cout << "Top element: " << strStack.top() << std::endl;
		strStack.push("This");
		strStack.push("is");
		strStack.push("the test");
		MutantStack<std::string>::iterator it = strStack.begin();
		while (it != strStack.end())
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<std::string> s(strStack);
		std::cout << s.top() << std::endl;
		std::cout << s.size() << std::endl;
	}
	return 0;
}
