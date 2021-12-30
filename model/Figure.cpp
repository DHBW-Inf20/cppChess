//
// Created by dominic on 25.12.21.
//

#include "Figure.hpp"

Figure::Figure(std::string name, int position) {
    this->setName(name);
    this->setPosition(position);
    this->setNotCaptured(true);
}

void Figure::setName(std::string name) {
    this->name = name;
}

void Figure::setPosition(int position) {
    this->position = position;
}

void Figure::setNotCaptured(bool notCaptured) {
    this->notCaptured = notCaptured;
}

std::string Figure::getName() {
    return this->name;
}

int Figure::getPosition() {
    return this->position;
}

bool Figure::getNotCaptured() {
    return this->notCaptured;
}

void Figure::setDelta(int delta1, int delta2, bool moveEndless, bool moveOnlyForward) {
    this->delta1 = delta1;
    this->delta2 = delta2;
    this->moveEndless = moveEndless;
    this->moveOnlyForward = moveOnlyForward;
}

int Figure::getDelta1() {
    return this->delta1;
}

int Figure::getDelta2() {
    return this->delta2;
}

bool Figure::isMoveEndless() {
    return this->moveEndless;
}

bool Figure::isMoveOnlyForward() {
    return this->moveOnlyForward;
}