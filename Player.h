#ifndef CIVILIZATION_V_PLAYER_H
#define CIVILIZATION_V_PLAYER_H


class Player {
private:
    int number;

public:
    explicit Player(int number);

    int getNumber() const;

    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
};


#endif //CIVILIZATION_V_PLAYER_H
