#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

#include "NPC.hpp"

class Werewolf : public NPC {
public:
    Werewolf(const std::string& name, float x, float y);
    ~Werewolf() override;

    void accept(Visitor& visitor, NPC& other) override;
    std::string getTypeName() const override;

    void print() const override;

};

#endif