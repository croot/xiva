/** @file mock_logger.hpp */
// xiva (acronym for HTTP Extended EVent Automata) is a simple HTTP server.
// Copyright (C) 2009 Yandex <highpower@yandex.ru>

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#ifndef XIVA_TESTS_MOCK_LOGGER_HPP_INCLUDED
#define XIVA_TESTS_MOCK_LOGGER_HPP_INCLUDED

#include "xiva/logger.hpp"

namespace xiva { namespace tests {

class mock_logger : public logger {

public:
	mock_logger();
	virtual ~mock_logger();

	virtual void info(char const *format, ...);
	virtual void debug(char const *format, ...);
	virtual void error(char const *format, ...);

private:
	mock_logger(mock_logger const &);
	mock_logger& operator = (mock_logger const &);
};

}} // namespaces

#endif // XIVA_TESTS_MOCK_LOGGER_HPP_INCLUDED
