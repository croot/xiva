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

#ifndef XIVA_PYTHON_PYTHON_ENUMERATION_HPP_INCLUDED
#define XIVA_PYTHON_PYTHON_ENUMERATION_HPP_INCLUDED

#include <boost/python.hpp>
#include "xiva/enumeration.hpp"

namespace py = boost::python;

namespace xiva { namespace python {

template <typename Item>
class python_enumeration : public enumeration<Item> {

public:
	python_enumeration();
	python_enumeration(py::tuple const &tuple);
	virtual ~python_enumeration();

	virtual Item next() const;
	virtual bool empty() const;

private:
	python_enumeration(python_enumeration const &);
	python_enumeration& operator = (python_enumeration const &);

private:
	py::tuple tuple_;
	mutable std::size_t number_;
};

template <typename Item> inline
python_enumeration<Item>::python_enumeration() :
		number_(0)
{
}

template <typename Item> inline
python_enumeration<Item>::python_enumeration(py::tuple const &tuple) :
		tuple_(tuple), number_(0)
{
}

template <typename Item> inline
python_enumeration<Item>::~python_enumeration() {
}

template <typename Item> inline Item
python_enumeration<Item>::next() const {
	// not implemented yet
	return Item();
}

template <typename Item> inline bool
python_enumeration<Item>::empty() const {
	return number_ == static_cast<std::size_t>(py::len(tuple_));
}

}} // namespaces

#endif // XIVA_PYTHON_PYTHON_ENUMERATION_HPP_INCLUDED
