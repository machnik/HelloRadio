#include "player.h"

Player::Player(QObject *parent) : QObject{parent} {}

void Player::setSource(const QString & source) {
    m_source = source;
}

const QString & Player::source() {
    return m_source;
}

