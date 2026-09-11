#include "PmergeMe.hpp"

std::vector<std::size_t> fordJohnsonOrder(std::size_t size)
{
    std::vector<std::size_t> order;
    std::size_t previous = 1;
    std::size_t current = 3;

    while (previous < size)
    {
        std::size_t index = current < size ? current : size;

        while (index > previous)
            order.push_back(--index);
            
        std::size_t next = current + 2 * previous;
        previous = current;
        current = next;
    }
    return order;
}

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.first < b.first;
}
