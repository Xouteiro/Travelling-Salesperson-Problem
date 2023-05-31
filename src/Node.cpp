#include "Node.h"

Node::Node(int id, double x, double y) {
    this->id = id;
    this->x = x;
    this->y = y;
}

int Node::getId() const {
    return id;
}

void Node::setId(int id) {
    Node::id = id;
}

double Node::getX() const {
    return x;
}

void Node::setX(double x) {
    Node::x = x;
}

double Node::getY() const {
    return y;
}

void Node::setY(double y) {
    Node::y = y;
}
