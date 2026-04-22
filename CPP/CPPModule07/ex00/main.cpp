/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:08:43 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/09/28 18:48:12 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Template.hpp"

e_random    generateType()
{
    
    static bool seeded = false;
        int         random;
    
        if (!seeded)
        {
            std::cout << "Generating two random variables of type INT, CHAR or STRING." << std::endl  << std::endl;
            srand(time(NULL));
            seeded = true;
        }
        random = rand() % 3;
        if (random == 0)
            return INT;
        else if (random == 1)
            return CHAR;
        else
            return STRING;
}

int main()
{

    e_random randomicType;
    
    randomicType = generateType();
    switch (randomicType)
    {
        case 0:
        {
            int x = 3;
            int y = 10;
            std::cout << "Function generateType() generated two variables of type INT:" << std::endl <<
                "x = " << x << "." << std::endl << "y = " << y << "." << std::endl << std::endl;
            std::cout << "Testing swap:" << std::endl;
            ::swap(x, y);
            std::cout << "Now check the values after swap:" << std::endl << "x = " << x << "." << std::endl <<
                "y = " << y << "." << std::endl;
            int min = ::min(x, y);
            int max = ::max(x, y);
            std::cout << "Trying to identify the smallest and the biggest between x and y." << 
            std::endl << "The min is: " << min << std::endl << "The max is: " << max << std::endl;
            break;
        }
        case 1:
        {
            char a = 'a';
            char b = 'A';
            std::cout << "Function generateType() generated two variables of type CHAR:" << std::endl <<
                "a = " << a << "." << std::endl << "b = " << b << "." << std::endl << std::endl;
            std::cout << "Testing swap:" << std::endl;
            ::swap(a, b);
            std::cout << "Now check the values after swap:" << std::endl << "a = " << a << "." << std::endl <<
                "b = " << b << "." << std::endl;
            char min = ::min(a, b);
            char max = ::max(a, b);
            std::cout << "Trying to identify the smallest and the biggest between a and b." << 
            std::endl << "The min is: " << min << std::endl << "The max is: " << max << std::endl;
            break;
        }
        case 2:
        {
            std::string s1 = "ciao";
            std::string s2 = "CIAO";
        
            std::cout << "Function generateType() generated two variables of type STRING:" << std::endl <<
                "s1 = " << s1 << "." << std::endl << "s2 = " << s2 << "." << std::endl << std::endl;
            std::cout << "Testing swap:" << std::endl;
            ::swap(s1, s2);
            std::cout << "Now check the values after swap:" << std::endl << "s1 = " << s1 << "." << std::endl <<
                "s2 = " << s2 << "." << std::endl;
            std::string min = ::min(s1, s2);
            std::string max = ::max(s1, s2);
            std::cout << "Trying to identify the smallest and the biggest between s1 and s2." << 
            std::endl << "The min is: " << min << std::endl << "The max is: " << max << std::endl;
            break;
        }
    }
}


/* #include <iostream>
#include "Template.hpp"
class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
} */
