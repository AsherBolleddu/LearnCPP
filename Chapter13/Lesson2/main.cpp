namespace Monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
} // namespace Monster

int main()
{
    [[maybe_unused]] Monster::MonsterType troll{Monster::troll};
    return 0;
}
