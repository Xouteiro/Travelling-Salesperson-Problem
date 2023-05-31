#ifndef PROJ2_NODE_H
#define PROJ2_NODE_H


class Node {
public:
    Node(int id, double x, double y);

    int getId() const;

    void setId(int id);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

private:
    int id;
    double x, y;
};


#endif
