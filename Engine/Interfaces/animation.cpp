#include "animation.h"
#include "cstdio"

Animation::Animation(){}

Animation::~Animation(){}

void Animation::restart(){}

bool Animation::pause(){
    return false;
}

void Animation::setPause(bool /*value*/){}

void Animation::setDelay(float /*d*/){}


AnimationManager::AnimationManager(){}

void AnimationManager::tick(){
    //printf("tick\n");
    for(std::set<Animation*>::iterator it = m_animations.begin();
            it != m_animations.end();it++){
        (*it)->tick();
    }
}

void AnimationManager::restart(){}

void AnimationManager::addAnimation(Animation *a){
    m_animations.insert(a);
}

void AnimationManager::removeAnimation(Animation *a){
    m_animations.erase(a);
}
