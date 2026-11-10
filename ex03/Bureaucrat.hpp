/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <bruno@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:20:08 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/11/05 09:14:29 by bruno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class   AForm;

class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        // OCF
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        
        // GETTERS
        std::string getName() const;
        int getGrade() const;
        
        // MEMBER FUNCTIONS
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(const AForm &form) const;

        // EXCEPTION CLASSES
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

// OVERLOAD << OPERATOR
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif