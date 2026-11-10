/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:20:08 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/11/10 10:26:51 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

/*
** Bureaucrat — a named employee with a grade from 1 (highest) to 150 (lowest).
*/
class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        /* OCF */
        Bureaucrat();
        // Throws GradeTooHigh/LowException if grade is outside [1, 150].
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        // Copies only _grade: _name is const.
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        /* GETTERS */
        std::string getName() const;
        int getGrade() const;
        
        /* MEMBER FUNCTIONS */
        // Grade 1 is highest: increment = grade - 1. Throws GradeTooHighException at 1.
        void incrementGrade();
        // Decrement = grade + 1. Throws GradeTooLowException at 150.
        void decrementGrade();

        /* EXCEPTIONS CLASSES */
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

// Prints: "<name>, bureaucrat grade <grade>."
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif