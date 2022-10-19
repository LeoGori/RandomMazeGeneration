//
// Created by leogori on 09/03/19.
//

#include "Tile.h"
#include <iostream>

using namespace std;

Tile::Tile() {
    father = nullptr;
    rank = 0;
}

void Tile::setValue(int val) {

    value=val;
}

int Tile::getValue() {

    return value;
}

int Tile::getRank() const {
    return rank;
}

void Tile::setRank(int rank) {
    this->rank = rank;
}

void Tile::setFather(Tile* father) {
    this->father = father;
}

Tile* Tile::getFather() {
    return father;
}

Tile* Tile::findSet() {
    if (father != nullptr)
        return father->findSet();
    return this;
}

void Tile::merge(Tile& tile) {

    Tile* thisRepresentative = findSet();
    Tile* otherRepresentative = tile.findSet();

/*    cout << thisRepresentative->getRank() << ", " << otherRepresentative-> getRank() << endl;

    cout << this << ", " << &tile << endl;

    cout << thisRepresentative << ", " << otherRepresentative << endl;*/

    if (thisRepresentative->getRank() > otherRepresentative->getRank())
        otherRepresentative->setFather(thisRepresentative);
    else {
        thisRepresentative->setFather(otherRepresentative);
        // cout << thisRepresentative->getFather() << endl;
        if (thisRepresentative->getRank() == otherRepresentative->getRank())
            otherRepresentative->setRank(otherRepresentative->getRank() + 1);
    }
}
