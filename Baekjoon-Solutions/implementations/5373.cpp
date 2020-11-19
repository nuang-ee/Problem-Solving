// https://www.acmicpc.net/problem/5373
// Cubing

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

/* each plane is represented as vector<char> plane[9].
 * index of each cell is as followed:
 * -------------
 * | 1 | 2 | 3 |
 * -------------
 * | 8 | 0 | 4 |
 * -------------
 * | 7 | 6 | 5 |
 * ------------- */

enum plane
{
    UP,
    DOWN,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

// for front, back, left, right, adjacent side to UP is north
// for up, adjacent side to BACK is north
// for down, adjacent side to FRONT is north
enum side
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

vector<int> getIndexBySide(enum side side)
{
    switch (side)
    {
    case NORTH:
        return {1, 2, 3};
    case EAST:
        return {3, 4, 5};
    case SOUTH:
        return {5, 6, 7};
    case WEST:
        return {7, 8, 1};
    default:
        cout << "error" << endl;
        exit(1);
    }
}

// return planes, in clockwise manner viewd from the parameter plane.
vector<pair<enum plane, enum side>> getSidePlane(enum plane plane)
{
    switch (plane)
    {
    case UP:
        return {make_pair(FRONT, NORTH), make_pair(LEFT, NORTH), make_pair(BACK, NORTH), make_pair(RIGHT, NORTH)};
    case DOWN:
        return {make_pair(FRONT, SOUTH), make_pair(RIGHT, SOUTH), make_pair(BACK, SOUTH), make_pair(LEFT, SOUTH)};
    case FRONT:
        return {make_pair(UP, SOUTH), make_pair(RIGHT, WEST), make_pair(DOWN, NORTH), make_pair(LEFT, EAST)};
    case BACK:
        return {make_pair(UP, NORTH), make_pair(LEFT, WEST), make_pair(DOWN, SOUTH), make_pair(RIGHT, EAST)};
    case LEFT:
        return {make_pair(UP, WEST), make_pair(FRONT, WEST), make_pair(DOWN, WEST), make_pair(BACK, EAST)};
    case RIGHT:
        return {make_pair(UP, EAST), make_pair(BACK, WEST), make_pair(DOWN, EAST), make_pair(FRONT, EAST)};
    default:
        cout << "error" << endl;
        exit(1);
    }
}

void debugPrintPlane(vector<vector<char>> cube, enum plane plane, bool upper)
{
    vector<char> target = cube[plane];
    cout << "\n"
         << ((upper) ? "upper:\n" : "side:\n");
    cout << target[1] << target[2] << target[3] << '\n';
    cout << target[8] << target[0] << target[4] << '\n';
    cout << target[7] << target[6] << target[5] << '\n';
    cout << '\n';
}

// mode ? clockwise : counterclockwise
void rotatePlane(vector<vector<char>> &cube, enum plane plane, bool mode)
{
    vector<pair<enum plane, enum side>> sides = getSidePlane(plane);

    // cout << "before\n";
    // debugPrintPlane(cube, plane, true);
    // for (auto e : sides)
    //     debugPrintPlane(cube, e.first, false);

    enum plane curPlane, nextPlane;
    enum side curSide, nextSide;

    vector<int> curThree;
    vector<int> nextThree;

    if (mode)
    {
        // rotate the main plane
        char eighth = cube[plane][8];
        char seventh = cube[plane][7];
        for (int i = 4; i > 1; i--)
        {
            cube[plane][2 * i] = cube[plane][2 * (i - 1)];
            cube[plane][2 * i - 1] = cube[plane][2 * (i - 1) - 1];
        }
        cube[plane][1] = seventh;
        cube[plane][2] = eighth;

        vector<int> firstThreeInd = getIndexBySide(sides[0].second);
        vector<char> firstThreeVal;
        for (int i = 0; i < 3; i++)
            firstThreeVal.push_back(cube[sides[0].first][firstThreeInd[i]]);

        // cout << "firstThreeInd : ";
        // for (auto e : getIndexBySide(sides[0].second))
        // {
        //     cout << e << ' ';
        // }
        // cout << '\n'
        //      << "firstThreeVal : ";
        // for (auto e : firstThreeVal)
        // {
        //     cout << e << ' ';
        // }
        // cout << '\n';

        // rotate side planes, clockwise
        for (int i = 3; i >= 0; i--)
        {
            tie(curPlane, curSide) = sides[i];
            tie(nextPlane, nextSide) = (i == 3) ? sides[0] : sides[i + 1];

            curThree = getIndexBySide(curSide);
            nextThree = getIndexBySide(nextSide);

            for (int j = 0; j < 3; j++)
            {
                // if (i == 3)
                // {
                //     cout << "replace " << cube[nextPlane][nextThree[j]] << " to " << cube[curPlane][curThree[j]] << '\n';
                // }
                cube[nextPlane][nextThree[j]] = (i == 0) ? firstThreeVal[j] : cube[curPlane][curThree[j]];
            }
        }
    }
    else
    {
        char first = cube[plane][1];
        char second = cube[plane][2];
        for (int i = 1; i < 4; i++)
        {
            cube[plane][2 * i] = cube[plane][2 * (i + 1)];
            cube[plane][2 * i - 1] = cube[plane][2 * (i + 1) - 1];
        }
        cube[plane][7] = first;
        cube[plane][8] = second;

        vector<int> lastThreeInd = getIndexBySide(sides[3].second);
        vector<char> lastThreeVal;
        for (int i = 0; i < 3; i++)
            lastThreeVal.push_back(cube[sides[3].first][lastThreeInd[i]]);

        // rotate side planes, clockwise
        for (int i = 0; i <= 3; i++)
        {
            tie(curPlane, curSide) = sides[i];
            tie(nextPlane, nextSide) = (i == 0) ? sides[3] : sides[i - 1];

            curThree = getIndexBySide(curSide);
            nextThree = getIndexBySide(nextSide);

            for (int j = 0; j < 3; j++)
                cube[nextPlane][nextThree[j]] = (i == 3) ? lastThreeVal[j] : cube[curPlane][curThree[j]];
        }
    }

    // cout << "after\n";
    // debugPrintPlane(cube, plane, true);
    // for (auto e : sides)
    //     debugPrintPlane(cube, e.first, false);
}

inline enum plane PlaneCharToEnum(char plane)
{
    switch (plane)
    {
    case 'U':
        return UP;
    case 'D':
        return DOWN;
    case 'F':
        return FRONT;
    case 'B':
        return BACK;
    case 'L':
        return LEFT;
    case 'R':
        return RIGHT;
    default:
        cout << "error" << endl;
        exit(1);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<vector<pair<char, char>>> testCases;
    int numTestCases, n;

    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        vector<pair<char, char>> transforms;
        string transform;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> transform;
            transforms.emplace_back(transform[0], transform[1]);
        }
        testCases.emplace_back(transforms);
    }

    vector<char> colorList = {'w', 'y', 'r', 'o', 'g', 'b'};
    for (int i = 0; i < numTestCases; i++)
    {
        vector<vector<char>> cube;
        for (auto c : colorList)
        {
            vector<char> cur_plane;
            for (int i = 0; i < 9; i++)
                cur_plane.push_back(c);
            cube.emplace_back(cur_plane);
        }

        for (auto move : testCases[i])
        {
            enum plane cur = PlaneCharToEnum(move.first);
            bool mode = (move.second == '+') ? true : false;
            rotatePlane(cube, cur, mode);
        }

        vector<char> upperPlane = cube[0];
        cout << upperPlane[1] << upperPlane[2] << upperPlane[3] << '\n';
        cout << upperPlane[8] << upperPlane[0] << upperPlane[4] << '\n';
        cout << upperPlane[7] << upperPlane[6] << upperPlane[5] << '\n';
    }
    return 0;
}