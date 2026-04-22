/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:06:10 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/11/22 17:07:14 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
    std::string temp = "data.csv";
    if (!loadCSV_data(temp))
        throw (std::runtime_error("Error: problem with data.csv"));
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other )
{
    this->CSVdata_map = other.CSVdata_map;
}

BitcoinExchange&    BitcoinExchange::operator=( const BitcoinExchange &other )
{
    if (this != &other)
        this->CSVdata_map = other.CSVdata_map;
    return *this;
}

bool        BitcoinExchange::is_valid_date(std::string date_str)
{
    if (date_str[4] != '-' || date_str[7] != '-')
    {
        std::cerr << "Error: '-' is in the wrong scope or absent. =>" << date_str << std::endl;
        return false;
    }
    std::string _day;
    std::string _month;
    std::string _year;
    
    _year = date_str.substr(0, 4);
    _month = date_str.substr(5, 2);
    _day = date_str.substr(8, 2);
    if (std::atoi(_day.c_str()) > 31 || std::atoi(_month.c_str()) > 12)
    {
        std::cerr << "Error: invalid date was found => " << date_str << std::endl;
        return false;
    }
    if (std::atoi(_year.c_str()) < 2009)
    {
        std::cerr << "Error: invalid date was found => " << date_str << ". First valid date is 2009-01-02."<< std::endl;
        return false;
    }
    if (std::atoi(_day.c_str()) == 01 && std::atoi(_month.c_str()) == 01 && std::atoi(_year.c_str()) == 2009)
    {
        std::cerr << "Error: invalid date was found => " << date_str << ". First valid date is 2009-01-02."<< std::endl;
        return false;
    }
    if (std::atoi(_day.c_str()) > 29 && std::atoi(_month.c_str()) > 03 && std::atoi(_year.c_str()) > 2022)
    {
        std::cerr << "Error: invalid date was found => " << date_str << ". Last valid date is 2022-03-29."<< std::endl;
        return false;
    }
    if (_day.size() != 2 || _month.size() != 2 || _year.size() != 4)
    {
        std::cerr << "Error: an invalid date was found. => " << date_str << std::endl;
        return false;
    }
    for (size_t i = 0; i < _day.length(); i++)
    {
        if (std::isdigit(_day[i]) == false)
        {
            std::cerr << "Error: in " << date_str << " " << _day[i] << " is not a digit." << std::endl;
            return false;
        }
    }
    for (size_t i = 0; i < _month.length(); i++)
    {
        if (std::isdigit(_month[i]) == false)
        {
            std::cerr << "Error: in " << date_str << " "  << _month[i] << " is not a digit." << std::endl;
            return false;
        }
    }
    for (size_t i = 0; i < _year.length(); i++)
    {
        if (std::isdigit(_year[i]) == false)
        {
            std::cerr << "Error: in " << date_str << " "  << _year[i] << " is not a digit." << std::endl;
            return false;
        }
    }
    return true;
}

bool            BitcoinExchange::is_valid_value(std::string value_str)
{
    float   temp;
    temp = atof(value_str.c_str());
    for (size_t i = 0; i < value_str.size(); i++)
    {
        if (!isdigit(value_str[i]) && value_str[i] != '.')
        {
            std::cerr << "Error: an invalid value was found => " << value_str << std::endl;
            return false;
        }
    }
    if ( static_cast<int>(temp) > 1000 || static_cast<int>(temp) < 0 )
    {
        std::cerr << "Error: an invalid value was found. => " << value_str << std::endl;
        return false;
    }
    return true;
}

bool        BitcoinExchange::process_inFile(std::string inFilename)
{
    std::ifstream   file(inFilename.c_str());
    std::string     line;
    int i;
    i = 0;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    if ( inFilename.find(".txt") != inFilename.size() - 4 || inFilename.substr(inFilename.length() - 4) != ".txt")
        std::cerr << "Error, invalid filename." << std::endl;
    while (std::getline(file, line))
    {

        if (line.empty())
        {
            std::cerr << "Error: invalid empty line in input file." << std::endl;
            return false;
        }
        if (i == 0)
        {
            std::string temp;
            temp = line;
            temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
            if ( temp == "date|value" )
            {
                i++;
                continue;
            }
            else
            {
                std::cerr << "Error: invalid header-line in input file." << std::endl;
            }
        }
        if (line.length() < 10 || line[11] != '|')
        {
            std::cerr << "Error: Malformed line was found => " << line << std::endl;
            i++;
            continue;
        }
        if(is_valid_date(line.substr(0, 10)) == false )
        {
            i++;
            continue;
        }
        if (line.length() < 13)
        {
            std::cerr << "Error: Malformed line was found => " << line << std::endl;
            i++;
            continue;
        }
        if (is_valid_value(line.substr(13)) == false)
        {
            i++;
            continue;
        }
        else
        {
            std::cout << line << " = " << findMatch(line) << std::endl;
            i++;
        }
    }
    file.close();
    return true;
}

float                BitcoinExchange::findMatch(std::string toFind)
{
    
    std::map<std::string, std::string>::iterator it = CSVdata_map.begin();
    long long int   i;
    i = 0;
   
    std::string toSearch = toFind.substr(0, 10);
    while (it != CSVdata_map.end())
    {
        if (toSearch == it->first)
        {
            float   amount = atof(toFind.substr(13).c_str());
            float   value = atof(it->second.c_str());
            return amount * value;
        }
        it++;
    }
    if (it == CSVdata_map.end())
    {
        it = CSVdata_map.lower_bound(toSearch);
        if (it != CSVdata_map.begin())
            it--;
        float   amount = atof(toFind.substr(13).c_str());
        float   value = atof(it->second.c_str());
        return amount * value;
    }
    return 0;
}

bool    BitcoinExchange::loadCSV_data(std::string &CSV_dataName)
{   
    std::string readingLine;
    std::string readingPrice;
    std::string readingDate;

    if (CSV_dataName != "data.csv")
    {
        std::cerr << ".csv filename is wrong. Only accept 'data.csv'" << std::endl;
        return false;
    }
    
    std::ifstream file(CSV_dataName.c_str());
    if (!file.is_open())
        return false;
    if (std::getline(file, readingLine))
    {
        if (readingLine != "date,exchange_rate")
            throw std::runtime_error("missing header line in data.csv. The file must be the original provided with the subject.");
    }
    while (std::getline(file, readingDate, ',') && std::getline(file, readingPrice))
        this->CSVdata_map.insert(std::make_pair(readingDate, readingPrice));
    
    file.close();
    return true;
}

BitcoinExchange::~BitcoinExchange()
{
    
}

