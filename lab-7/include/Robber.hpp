#ifndef ROBBER_HPP
#define ROBBER_HPP

#include "NPC.hpp"

struct Robber : public NPC {
    Robber(const std::string& name, int x, int y);
    ~Robber() override = default;

    void accept(Visitor& visitor, std::shared_ptr<NPC> other) override;
    void print() const override;
    void save(std::ostream& os) const override;
};

#endif