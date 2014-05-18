#include "terrain.h"

Terrain::Terrain(){
}
uint Terrain::id() const{
    return m_id;
}

void Terrain::setId(const uint &id){
    m_id = id;
}

