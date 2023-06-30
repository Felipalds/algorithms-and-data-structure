#include <vector>
#include <iostream>

int min(std::vector<int> v)
{
    int minimum = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < minimum)
        {
            minimum = v[i];
        }
    }
    return minimum;
}

int inside_vector(std::vector<int> item, std::vector<std::vector<int>> v)
{
    int inside = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (item[0] == v[i][0] && item[1] == v[i][1])
        {
            inside = 1;
        }
    }
    return inside;
}

class Cave
{
private:
    std::vector<std::vector<int>> cave_matrix;
    std::vector<int> gugo_position;
    std::vector<int> paths;
    int steps = 0;

    void get_shortest_path(std::vector<std::vector<int>> visited, std::vector<int> pos, int distance)
    {
        int lines = this->cave_matrix.size();
        int columns = this->cave_matrix[0].size();
        int l = pos[0];
        int c = pos[1];
        this->steps++;
        if (this->cave_matrix[l][c] == 0)
        {
            this->paths.push_back(distance);
        }
        else
        {
            // up
            std::vector<int> up_position{l - 1, c};
            if (l - 1 >= 0 && this->cave_matrix[l - 1][c] != 2 && !(inside_vector(up_position, visited)))
            {
                std::vector<std::vector<int>> new_visited = visited;
                new_visited.push_back(up_position);
                get_shortest_path(new_visited, up_position, (distance + 1));
            }
            // down
            std::vector<int> down_position{l + 1, c};
            if (l + 1 < lines && this->cave_matrix[l + 1][c] != 2 && !(inside_vector(down_position, visited)))
            {
                std::vector<std::vector<int>> new_visited = visited;
                new_visited.push_back(down_position);
                get_shortest_path(new_visited, down_position, (distance + 1));
            }
            // right
            std::vector<int> right_position{l, c + 1};
            if (c + 1 < columns && this->cave_matrix[l][c + 1] != 2 && !(inside_vector(right_position, visited)))
            {
                std::vector<std::vector<int>> new_visited = visited;
                new_visited.push_back(right_position);
                get_shortest_path(new_visited, right_position, (distance + 1));
            }
            // left
            std::vector<int> left_position{l, c - 1};
            if (c - 1 >= 0 && this->cave_matrix[l][c - 1] != 2 && !(inside_vector(left_position, visited)))
            {
                std::vector<std::vector<int>> new_visited = visited;
                new_visited.push_back(left_position);
                get_shortest_path(new_visited, left_position, (distance + 1));
            }
        }
    }

public:
    Cave(std::vector<std::vector<int>> cave_matrix)
    {
        this->cave_matrix = cave_matrix;
        for (int i = 0; i < this->cave_matrix.size(); i++)
        {
            for (int j = 0; j < this->cave_matrix[0].size(); j++)
            {
                if (this->cave_matrix[i][j] == 3)
                {
                    this->gugo_position = std::vector<int>{i, j};
                }
            }
        }
    };

    int shortest_path()
    {

        this->paths.clear();
        std::vector<std::vector<int>> visited;
        visited.push_back(this->gugo_position);
        int distance = 0;

        get_shortest_path(visited, this->gugo_position, distance);
        return min(this->paths);
    }
};

int main()
{
    int lines, columns;
    std::cin >> lines;
    std::cin >> columns;
    std::vector<std::vector<int>> cave_matrix;
    for (int i = 0; i < lines; i++)
    {
        cave_matrix.push_back(std::vector<int>{});
        for (int j = 0; j < columns; j++)
        {
            int n;
            std::cin >> n;
            cave_matrix[i].push_back(n);
        }
    }
    Cave myCave(cave_matrix);
    std::cout << myCave.shortest_path() << '\n';
    return 0;
}
