#ifndef ROBBER_HPP
#define ROBBER_HPP

#include "NPC.hpp"

class Robber : public NPC {
public:
    Robber(const std::string& name, float x, float y);
    ~Robber() override;

    void accept(Visitor& visitor, NPC& other) override;
    std::string getTypeName() const override;

    void print() const override;

};

#endif