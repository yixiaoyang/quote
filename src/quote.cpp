//
//  quote.cpp
//  quote
//
//  Copyright (C) 2013, 2014  André Pereira Henriques
//  aphenriques (at) outlook (dot) com
//
//  This file is part of quote.
//
//  quote is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  quote is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with quote.  If not, see <http://www.gnu.org/licenses/>.
//

#include "quote.h"
#include <initializer_list>
#include <string>
#include "conversion.h"
#include "core.h"
#include "QuoteType.h"

namespace quote {
    std::string getLatestQuotesCsv(const std::string &instruments, std::initializer_list<QuoteType> quoteTypes) {
        std::string quoteTypesString;
        for (QuoteType quoteType : quoteTypes) {
            quoteTypesString.append(detail::conversion::getString(quoteType));
        }
        return detail::core::getLatestQuotesCsv(instruments, quoteTypesString);
    }
}