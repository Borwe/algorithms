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
