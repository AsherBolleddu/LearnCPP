int sumTo(int value)
{
    int sum{};
    for (int i{1}; i <= value; ++i)
    {
        sum += i;
    }

    return sum;
}
