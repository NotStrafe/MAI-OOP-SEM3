#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

#include "NPC.hpp"

struct Werewolf : public NPC {
    Werewolf(const std::string& name, int x, int y);
    ~Werewolf() override = default;

    void accept(Visitor& visitor, std::shared_ptr<NPC> other) override;
    void print() const override;
    void save(std::ostream& os) const override;
};

#endif