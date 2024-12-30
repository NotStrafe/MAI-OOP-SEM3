#ifndef ORC_HPP
#define ORC_HPP

#include "NPC.hpp"

struct Orc : public NPC {
    Orc(const std::string& name, int x, int y);
    ~Orc() override = default;

    void accept(Visitor& visitor, std::shared_ptr<NPC> other) override;
    void print() const override;
    void save(std::ostream& os) const override;
};

#endif