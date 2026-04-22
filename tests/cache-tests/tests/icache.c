int main()
{
    for (volatile register int i = 0; i < 10000; i++)
    {
        asm volatile("nop\nnop\nnop\nnop\nnop");
    }
    return 0;
}
