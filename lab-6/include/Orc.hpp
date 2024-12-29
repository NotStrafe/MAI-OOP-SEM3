#ifndef ORC_HPP
#define ORC_HPP

#include "NPC.hpp"

class Orc : public NPC {
public:
    Orc(const std::string& name, float x, float y, int strength);
    ~Orc() override;

    void accept(Visitor& visitor, NPC& other) override;
    std::string getTypeName() const override;

    void print() const override;

private:
    int strength_;
};

#endif