C++ container test
==============

Testing performance of containers in C++

Testing prodedure:

1. Create random item
2. Insert each item, one by one in the correct place so container is sorted
3. Repeat 1 and 2 N times
4. As long as there are items in container pick random position in container and remove the item

Procedure repeat for:
- vector + int
- vector + struct
- list + int
- list + struct

Test proposed by `John Bentley` and presented by `Bjarne Stroustrup`

Compile
-------

```bash
g++ -Ofast -std=c++11 -o test_containers vl.cpp
```

Execute
-------

To execute application run command below. As arguments please specify number of elements (in thousands) in each test.

```bash
./test_containers 1 2 5 10 20 50
```

My results
----------

Results of tests so far. And no there is no mistake between Vector and List

| Size    | Vector(int) | List(int) | Vector(struct) | List(struct) |
|:-------:|:-----------:|:---------:|:--------------:|:------------:|
| 1000    | 0.002075    | 0.003745  | 0.008245       | 0.003806     |
| 2000    | 0.002314    | 0.011299  | 0.018225       | 0.022979     |
| 5000    | 0.013703    | 0.101056  | 0.125336       | 0.370587     |
| 10000   | 0.054041    | 0.699669  | 0.544398       | 1.83573      |
| 20000   | 0.219911    | 5.42762   | 2.2763         | 10.2953      |
| 50000   | 1.38206     | 46.9542   | 21.519         | 193.786      |
| 80000   | 3.60116     | 170.99    | 70.3451        | 648.37       |
| 100000  | 5.58604     | 346.308   | 117.416        | 1084.59      |
| 150000  | 12.6712     | 1424.19   | 299.114        | 2657.88      |
| 200000  | 22.5725     | 3860.96   | 569.221        | 5072.31      |
