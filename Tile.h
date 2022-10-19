//
// Created by Leonardo on 16/10/22.
//

#ifndef MAZE_RANDOM_GENERATION_TILE_H
#define MAZE_RANDOM_GENERATION_TILE_H

class Tile {
public:

    Tile();

    void setValue(int val);

    int getValue();

    int getRank() const;

    void setRank(int rank);

    void setFather(Tile *father);

    Tile* getFather();

    Tile* findSet();

    void merge(Tile& tile);

private:

    int value;

    int rank;

    Tile* father;

};


#endif //MAZE_RANDOM_GENERATION_TILE_H
