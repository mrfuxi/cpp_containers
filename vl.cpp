#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

struct SimpleStruct {
    int id;
    double n1;
    double n2;
    char name[80];

    SimpleStruct(int id) : id(id) {};

    bool operator<(const SimpleStruct& rhs) const
    {
        return id < rhs.id;
    }
};

template<typename C, typename E>
double test_container(int no) {
    C container;
    struct timeval t0, t1;

    gettimeofday(&t0, NULL);

    for (int i=0; i<no; i++)
    {
        E new_value {rand()};

        if (container.empty())
        {
            container.push_back(new_value);
            continue;
        }

        bool added = false;
        auto it = container.begin();
        for (; it != container.end(); ++it)
        {
            if (new_value < *it)
            {
                container.insert(it, new_value);
                added = true;
                break;
            }
        }

        if (!added)
        {
            container.insert(container.end(), new_value);
        }
    }

    int to_remove;
    do {
        to_remove = rand() % container.size();

        int pos = 0;
        for (auto it = container.begin(); it != container.end(); ++it)
        {
            if (to_remove == pos)
            {
                container.erase(it);
                break;
            }
            pos++;
        }
    } while(!container.empty());

    gettimeofday(&t1, NULL);

    double time_taken = ((t1.tv_sec*1000000.0+t1.tv_usec) - (t0.tv_sec*1000000.0+t0.tv_usec))/1000000.0;
    return time_taken;
}

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        std::cerr << "More then arguments expected.\n";
        return 1;
    }

    srand(time(NULL));

    std::cerr << "Size,Vector(int),List(int),Vector(struct),List(struct)\n";
    for (int i=1; i<argc; i++)
    {
        int no = 1000 * atoi(argv[i]);
        double v_time_int = test_container<std::vector<int>, int>(no);
        double l_time_int = test_container<std::list<int>, int>(no);
        double v_time_struct = test_container<std::vector<SimpleStruct>, SimpleStruct>(no);
        double l_time_struct = test_container<std::list<SimpleStruct>, SimpleStruct>(no);
        std::cout << no << ","
                  << v_time_int << ","
                  << l_time_int << ","
                  << v_time_struct << ","
                  << l_time_struct
                  << std::endl;
    }

    return 0;
}
