//Copyright (C) 2021  Brian Orwe
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.


#ifndef NODE_H
#define NODE_H

#include "dymamic_preproc.h"
#include <memory>

template<typename Item>
class Node{
private:
public:
    Item item;
    std::shared_ptr<Node> next;

    Node()=default;
};

template<typename Item>
using ShNode=std::shared_ptr<Node<Item>>;

#endif
