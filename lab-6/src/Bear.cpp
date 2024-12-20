#include "../include/Bear.hpp"

Bear::Bear(const std::string& name, int x, int y) : NPC(BearType, name, x, y) {}
Bear::Bear(std::istream& is) : NPC(BearType, is) {}

bool Bear::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Bear> defender = std::dynamic_pointer_cast<Bear>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Bear::print() {
    std::cout << *this;
}

void Bear::save(std::ostream& os) {
    os << BearType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Bear& Bear) {
    os << "Bear " << *static_cast<NPC*>(&Bear) << std::endl;
    return os;
}