#ifndef PROJ2_NODE_H
#define PROJ2_NODE_H


/**
 * @brief This class represents a node in the graph
 */
class Node {
private:
    int id;
    double x, y;
public:
    /**
     * Constructor for the Node class
     * @param id id of the node
     * @param x x coordinate of the node (latitude)
     * @param y y coordinate of the node (longitude)
     */
    Node(int id, double x, double y);

    /**
     * Getter for the id of the node
     * @return id of the node
     */
    int getId() const;

    /**
     * Setter for the id of the node
     * @param id id of the node
     */
    void setId(int id);

    /**
     * Getter for the x coordinate of the node
     * @return x coordinate of the node
     */
    double getX() const;

    /**
     * Setter for the x coordinate of the node
     * @param x x coordinate of the node
     */
    void setX(double x);

    /**
     * Getter for the y coordinate of the node
     * @return y coordinate of the node
     */
    double getY() const;

    /**
     * Setter for the y coordinate of the node
     * @param y y coordinate of the node
     */
    void setY(double y);
};


#endif
