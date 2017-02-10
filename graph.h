/*
    Copyright (c) 2017 Naveen Venkat
    github.com/nmakes/ds
    Read licence for more info
*/

#include "list.h"


class gnode
{
    private:
    List <gnode *> edge;

    public:
    void addEdge(gnode*);
    void removeEdge(gnode*);
    void connect(gnode*);
    void disconnect(gnode*);
};

class graph
{
    private:
    List <gnode *> nodes;
};

void gnode::addEdge(gnode * gn)
{
    this->edge.add(gn);
}

void gnode::removeEdge(gnode * gn)
{
    this->edge.remove(gn);
}

void gnode::connect(gnode * gn)
{
    this->edge.addEdge(gn);
    gn->edge.addEdge(this);
}

void gnode::disconnect(gnode * gn)
{

}
