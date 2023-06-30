#include <vector>
#include <iostream>

int max(std::vector<int> n)
{
    int greatest = n[0];
    for (int i = 1; i < n.size(); i++)
    {
        if (n[i] > greatest)
        {
            greatest = n[i];
        }
    }
    return greatest;
}

int sum(std::vector<int> n)
{
    int summation = 0;
    for (int i = 0; i < n.size(); i++)
    {
        summation += n[i];
    }
    return summation;
}

class Worms
{
private:
    std::vector<std::vector<int>> worm_matrix;

public:
    Worms(std::vector<std::vector<int>> worm_matrix)
    {
        this->worm_matrix = worm_matrix;
    };

    int highest_worm_line()
    {
        std::vector<int> worms_lines;
        for (int i = 0; i < this->worm_matrix.size(); i++)
        {
            worms_lines.push_back(sum(this->worm_matrix[i]));
        }
        for (int i = 0; i < this->worm_matrix[0].size(); i++)
        {
            std::vector<int> worms;
            for (int j = 0; j < this->worm_matrix.size(); j++)
            {
                worms.push_back(this->worm_matrix[j][i]);
            }
            worms_lines.push_back(sum(worms));
            worms.clear();
        }
        return max(worms_lines);
    };
};

int main()
{
    int lines, columns;
    std::cin >> lines;
    std::cin >> columns;
    std::vector<std::vector<int>> worm_matrix;
    for (int i = 0; i < lines; i++)
    {
        worm_matrix.push_back(std::vector<int>{});
        for (int j = 0; j < columns; j++)
        {
            int worm_number;
            std::cin >> worm_number;
            worm_matrix[i].push_back(worm_number);
        }
    }
    Worms myWorms(worm_matrix);
    std::cout << myWorms.highest_worm_line() << '\n';
    return 0;
}
