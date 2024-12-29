#include <gtest/gtest.h>

#include "../include/Bear.hpp"
#include "../include/Npc.hpp"
#include "../include/Elf.hpp"
#include "../include/Rogue.hpp"
#include "../include/Visitor.hpp"

TEST(npc_test, accept_test) {
    std::shared_ptr<NPC> elf, bear, rogue;
    elf = std::make_shared<Elf>("George", 0, 15);
    bear = std::make_shared<Bear>("John", 50, 15);
    rogue = std::make_shared<Rogue>("David", 100, 15);

    ASSERT_FALSE(bear->accept(elf));
    ASSERT_FALSE(elf->accept(elf));
    ASSERT_TRUE(rogue->accept(elf));
    ASSERT_FALSE(rogue->accept(bear));
    ASSERT_TRUE(elf->accept(bear));
    ASSERT_FALSE(bear->accept(bear));
    ASSERT_FALSE(elf->accept(rogue));
    ASSERT_FALSE(bear->accept(rogue));
    ASSERT_TRUE(rogue->accept(rogue));
}

TEST(npc_test, is_close_test) {
    std::shared_ptr<NPC> elf, bear, rogue;
    elf = std::make_shared<Elf>("George", 0, 15);
    bear = std::make_shared<Bear>("John", 50, 15);
    rogue = std::make_shared<Rogue>("David", 100, 15);

    ASSERT_TRUE(elf->is_close(bear, 50));
    ASSERT_TRUE(elf->is_close(rogue, 100));
    ASSERT_FALSE(elf->is_close(bear, 25));
    ASSERT_FALSE(elf->is_close(rogue, 50));
}

TEST(visitor_test, visit_test) {
    std::shared_ptr<NPC> elf, bear, rogue;
    std::shared_ptr<Visitor> elf_visitor, bear_visitor, rogue_visitor;
    elf = std::make_shared<Elf>("George", 0, 15);
    bear = std::make_shared<Bear>("John", 50, 15);
    rogue = std::make_shared<Rogue>("David", 100, 15);

    elf_visitor = std::make_shared<ElfVisitor>();
    bear_visitor = std::make_shared<BearVisitor>();
    rogue_visitor = std::make_shared<RogueVisitor>();

    ASSERT_FALSE(elf_visitor->visit(std::static_pointer_cast<Elf>(elf)));
    ASSERT_FALSE(elf_visitor->visit(std::static_pointer_cast<Bear>(bear)));
    ASSERT_TRUE(elf_visitor->visit(std::static_pointer_cast<Rogue>(rogue)));
    ASSERT_TRUE(bear_visitor->visit(std::static_pointer_cast<Elf>(elf)));
    ASSERT_FALSE(bear_visitor->visit(std::static_pointer_cast<Bear>(bear)));
    ASSERT_FALSE(bear_visitor->visit(std::static_pointer_cast<Rogue>(rogue)));
    ASSERT_FALSE(rogue_visitor->visit(std::static_pointer_cast<Elf>(elf)));
    ASSERT_FALSE(rogue_visitor->visit(std::static_pointer_cast<Bear>(bear)));
    ASSERT_TRUE(rogue_visitor->visit(std::static_pointer_cast<Rogue>(rogue)));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}