Tree-shape data structures:

1. Binary Tree, blabla (Simple Conclusion of what we have learned)
2. Balanced Tree->AVL Tree, Red-Black Tree, B-Tree, B+Tree, B*Tree( Red-Black Tree typicaly)
3. KD-Tree, Binary Space Partitioning Tree(BSP Tree), and it's applications (E.X., 3D Rendering, another project about geographics)
4. QuadTree, Octree, 2^n-tree?(Mathematical Induction? What other can we talk about?)

---
First part of the project: Implement Red-Black Tree, AVL and B+ tree. 

Must have these functions:
- **insert**
- **delete**
- **search**
- **print**
- **rebalancing counting**
-  3 kinds of **traversal** methods. (inorder, preorder, postorder)

Second part of the project: Implement the comparison of peformances (RBT-AVL, RBT- B+) in these aspects:
- **insert**
- **delete**
- **search**
- **traversal**
- **time used for rebalancing**
- different size and randomness of data.

This part may have some problems like CMake, implementation of a universal time-scaling function (.h?), visualization and analysis of data, etc.

Note: all comparison must be done on **school's server**(to guarantee there's no difference in hardware).

---
RNG.h ok
BPT.h ok
AVL.h ok
---
Update in 20231204:
What we'll do next:
1, copy the main.cpp i post on github (it's more a template than a well-implemented program for running your test)
2, do performance test between RedBlackTree and the tree your group has done based on the templates provided by main.cpp
3, collect data, organize them and get results. Write them down
4, don't forget to upload the simulation program, the CMake file and the result to github: TreeAlgorithms/Comparison/[Corresponding File]
Note:
1, All programs and results should run on SCHOOL'S VIRTUAL MACHINE!!! (to keep consistency)
2, what need to be done:
2.1, time for building a tree using our random number generator
2.2, time for traveling the whole tree (pre/in/post order)
2.3, time to query a random data ( in random place(root/branch/leaf), to test the average performance of query)
2.4, time for add a new node  (in random place, to test the average performance of add)
2.5, time for deleting a existing node (in random place, to test the average performance of delete)
on different:
3.1 scale of dataset
          (1k?1M? Or more? How large the scale will lead a noticeable difference?)
3.2 randomness of data
          (sort/unsort)
Due time:   This Wednesday's  midnight (23:59, 1204, 2023)
PS. B+ tree is quite different from AVL-like trees, and I will figure how to make it out with Shum
---