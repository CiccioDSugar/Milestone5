/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:48:32 by fzuccaro          #+#    #+#             */
/*   Updated: 2025/10/17 20:52:53 by fzuccaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private:
        
        std::map<std::string, std::string>   CSVdata_map;

        bool            loadCSV_data(std::string &CSV_dataName);
        bool            is_valid_value(std::string value_str);
        bool            is_valid_date(std::string date_str);
    public:
        float                findMatch(std::string filename);
        bool                process_inFile(std::string inFilename);
                            BitcoinExchange();
                            BitcoinExchange( const std::string &CSV_dataName );
                            BitcoinExchange( const BitcoinExchange &other );
        BitcoinExchange&    operator=(const BitcoinExchange &other);
                            ~BitcoinExchange();

        
    

};

#endif