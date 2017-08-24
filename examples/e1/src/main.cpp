#include <iostream>
#include <vector>
#include <array>

#include <algorithm>

// function kdtree (list of points pointList, int depth)
// {
//     // Select axis based on depth so that axis cycles through all valid values
//     var int axis := depth mod k;
        
//     // Sort point list and choose median as pivot element
//     select median by axis from pointList;
        
//     // Create node and construct subtree
//     node.location := median;
//     node.leftChild := kdtree(points in pointList before median, depth+1);
//     node.rightChild := kdtree(points in pointList after median, depth+1);
//     return node;
// }

template<typename T> size_t size(std::vector<T> v){ return v.size(); }
template<typename T, size_t I> size_t size(std::array<T, I> a){ return I; }

struct Branch{};

struct Node{
    std::array<float, 2> data;
    double location;
    Branch leftChild;
    Branch rightChild;
};
// quand on est dans un noeud, les points qui sont stockes a gauche sont inf,
// a droite -> superieur


// La contrainte sur la sélection du point médian n'est pas une obligation, mais permet de s'assurer que l'arbre sera équilibré. Le tri des points à chaque étape a un coût en temps, ce qui peut amener à un temps de création de l'arbre assez long.

bool is_even(const int i)
{
    return i % 2 == 0;
};

float median(const std::vector<std::array<float, 2>>& points, const int axis)
{
    if ( is_even(size(points)) )
      return (points[size(points) / 2 - 1][axis] + points[size(points) / 2][axis]) / 2.0;
    else 
      return points[size(points) / 2][axis];
}


auto left = [](const auto& a, const auto& b){ return a <= b; };
auto right = std::greater<float>();

std::vector<std::array<float, 2>> split(const std::vector<std::array<float, 2>>& points, const double median, const int axis, auto left_or_right)
{
    std::vector<std::array<float, 2>> new_points;

    for (auto& p : points)
    {
        if ( left_or_right(p[axis], float(median)) )
            new_points.push_back(p);
    }

    return new_points;
}

// variable qui sert a verif qu'on va pas tomber dans l'inf iteration
static size_t previous_size = 0;

bool stop(const std::vector<std::array<float, 2>>& points, double depth)
{
    return size(points) < 1
        or size(points) == previous_size
        ;
    ;
}

Node kdtree(const std::vector<std::array<float, 2>>& points, const int depth = 0)
{
    Node node;
    int k = points[0].size(); //dimension d un point

    if (stop(points, depth))
        return node;
    previous_size = size(points);

    // Select axis based on depth so that axis cycles through all valid values
    // 0 < axis < k
    int axis = depth % k;
    // std::cout << "depth(" << depth << "), axis(" << axis << ")" << std::endl;

    for (auto& p : points)
    {
        std::cout << p.at(axis) << ", ";
    }
    std::cout << std::endl;

    // Sort point list and choose median as pivot element
    // select median by axis from pointList;

    double med = median(points, axis);
    std::cout << "median: " << med << std::endl;
    std::cout << std::endl;

    // Create node and construct subtree
    node.location = med;
    // node.leftChild =
    kdtree(split(points, med, axis, left), depth + 1);
    // node.rightChild = kdtree(split(points, med, axis, right), depth + 1);

    return node;
}

// ON TRAVAIL AVEC UN SORTED VECTOR
int main()
{
    // std::vector<std::array<float, 2>> points2D { {1,1},{3,3},{3,3},{6,6},{7,7},{8,8},{9,9} }; // ordered
    // std::vector<std::array<float, 2>> points2D { {4,4},{5,5},{6,6},{8,8},{9,9}, {1,1},{2,2},{3,3} }; // unordered
    std::vector<std::array<float, 2>> points2D { {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{8,8},{9,9} }; // ordered

    // std::vector<std::array<float, 2>> points2D { {0,0},{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},{10,10},{11,11} };
    // std::vector<std::array<float, 3>> points3D { {0,0,0},{1,1,1},{2,2,2},{3,3,3},{4,4,4},{5,5,5},{6,6,6},{7,7,7},{8,8,8},{9,9,9},{10,10,10},{11,11,11} };

    kdtree(points2D);

    return 0;
}