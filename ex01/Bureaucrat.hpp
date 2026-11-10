/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:20:08 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/11/10 10:31:10 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

// Forward declaration: avoids circular include with Form.hpp
class   Form;

class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        /* OCF */
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        /* GETTERS */
        std::string getName() const;
        int getGrade() const;
        
        /* MEMBER FUNCTIONS */
        void incrementGrade();
        void decrementGrade();
        // Tries to sign form. Prints success or the reason of failure (never throws).
        void signForm(Form &form);

        /* EXCEPTION CLASSES */
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