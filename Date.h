#pragma once
#include <string>
#include <sstream>
#include <iostream>
class Date
{
    private:
    int day, months, year;
    std::string dateInString;
    public:
Date(int inMonth, int inDay, int inYear) : months(inMonth), day(inDay), year(inYear) {};
	void formatDate() {
		std::cout << months << "/" << day << "/" << year;
		//return day;
	}
	
	void incrementDay() {
		++day;
        if(day>31 && months == 1 ||months == 3 ||months == 5 ||months == 7 ||months == 8 ||months == 10){
         incrementMes();
         day = 1;
        } else if(day>30 && months == 4 || months == 6 || months==9 || months == 11){
        incrementMes();
        day = 1;
        }else if(months == 12 && day>31){
        incrementYear();
        day = 1;
        months = 1;
        }else if (months == 2){
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
                if(day>29){
                    incrementMes();
                    day=1;
                }
            }else if(day>28){
                incrementMes();
                day=1;
            }
        }
        
	}
	void incrementMes() {
		months++;
        if(months>12){
            incrementYear();
            months=1;
        }
	}
	void incrementYear() {
		year++;
	}
	void DecrementDay() {
		--day;
        if(day<1 && months == 4 ||months == 6 ||months == 9 ||months == 11 ||months == 2){
         DecrementMes();
         day = 31;
        } else if(day<1 && months == 12 || months == 10 || months==7 || months == 5){
        DecrementMes();
        day = 30;
        }else if(months == 1 && day<1){
        DecrementYear();
        day = 31;
        months = 12;
        }else if (months == 3){
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
                if(day<1){
                    DecrementMes();
                    day=29;
                }
            }else if(day<1){
                DecrementMes();
                day=28;
            }
        }
	}
	void DecrementMes() {
		months--;
	}
	void DecrementYear() {
		year--;
	}
	Date operator +(int daysInAdd) {
		Date newDate(months, day, year);
		return newDate;
	}

	//Esto es para prefix
	//Prefix: Poner el operador antes de la variable
	Date& operator ++() {
		++day;
		return *this;
	}
	Date& operator --() {
		--day;
		return *this;
	}
	//Esto es para profix
	
	Date operator ++(int) {
		Date copy(months, day, year);
		++day;
		return *this;
	}

	Date operator --(int) {
		Date copy(months, day, year);
		--day;
		return *this;
	}
	
	operator const char* () {
		std::ostringstream formatDate;
		formatDate << months << "/" << day << "/" << year;
		dateInString = formatDate.str();
		return dateInString.c_str();
	}
};
