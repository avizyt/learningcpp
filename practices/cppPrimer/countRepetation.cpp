#include <iostream>
int main()
{
    // currValisthe numberwe’re counting; we’ll read new values into val
    int currVal = 0, val = 0;
    // read first number and ensure that we have data to process
    if (std::cin >> currVal)
    {
        int cnt = 1; // storethecountforthecurrent value we’re processing
        while (std::cin >> val)
        {                       // readtheremainingnumbers
            if (val == currVal) // ifthevaluesarethesame
                ++cnt;
            // add1tocnt
            else
            { // otherwise, print the count for the previous value
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;
                // remember the new value
                cnt = 1;
            }
        } // whileloopendshere
        // reset the counter
        // remember to print the count for the last value in the file
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    } // outermost ifstatement ends here
    return 0;
}