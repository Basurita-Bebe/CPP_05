/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:20:08 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/11/03 11:35:01 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        // Canonical form
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        // Getters
        std::string getName() const;
        int getGrade() const;
        
        // Member functions
        void incrementGrade();
        void decrementGrade();

        // Exception classes
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

// Overload insertion operator for Bureaucrat
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif