#include <iostream>
#include <iomanip>
#include "HeaderFiles/BinaryTree.h"
#include "HeaderFiles/Treap.h"
#include <limits>
#include <string>

using namespace std;

bool ValidateIntegerInput(int& input)
{
    while (true)
    {
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid integer: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
    }
}

void PrintMainMenu()
{
    cout << "\nMain Menu\n";
    cout << "[1] Binary Tree\n";
    cout << "[2] Treap\n";
    cout << "[0] Exit\n";
}

void PrintBinaryTreeMenu()
{
    cout << "\nBinary Tree Menu\n";
    cout << "[1] Add\n";
    cout << "[2] Is exist?\n";
    cout << "[3] Remove an element\n";
    cout << "[4] Show the minimum element\n";
    cout << "[5] Show the maximum element\n";
    cout << "[6] Clear\n";
    cout << "[0] Return to main menu\n";
}

void PrintTreapMenu()
{
    cout << "\nTreap Menu\n";
    cout << "[1] Add\n";
    cout << "[2] Is exist?\n";
    cout << "[3] Remove an element\n";
    cout << "[4] Clear\n";
    cout << "[0] Return to main menu\n";
}

void PrintTree(const BinaryTreeNode* node, int depth = 0)
{
    if (node == nullptr)
    {
        return;
    }
    PrintTree(node->Right, depth + 1);
    cout << setw(4 * depth) << "" << node->Data << "\n";
    PrintTree(node->Left, depth + 1);
}

void PrintTree(const TreapNode* node, int depth = 0)
{
    if (node == nullptr)
    {
        return;
    }
    PrintTree(node->Right, depth + 1);
    cout << setw(4 * depth) << "" << node->Key << "(" << node->Priority << ")\n";
    PrintTree(node->Left, depth + 1);
}

int main()
{
    BinaryTree binaryTree;
    Treap treap;
    bool flag = true;
    int mainChoice, subChoice, key, priority;
    do
    {
        if (flag)
        {
            PrintMainMenu();
            cout << "Your choice: ";
        }
        ValidateIntegerInput(mainChoice);
        switch (mainChoice)
        {
        case 1:
            do
            {
                system("cls");
                PrintTree(binaryTree.GetNode());
                cout << "\n";
                PrintBinaryTreeMenu();
                cout << "Your choice: ";
                ValidateIntegerInput(subChoice);

                switch (subChoice)
                {
                case 1:
                {
                    cout << "Enter a key to add to the binary tree: ";
                    ValidateIntegerInput(key);
                    binaryTree.Add(key);
                    flag = false;
                    break;
                }
                case 2:
                {
                    cout << "Enter a key to find in the binary tree: ";
                    ValidateIntegerInput(key);
                    if (binaryTree.Find(binaryTree.GetNode(), key))
                    {
                        cout << "Element found.\n";
                    }
                    else
                    {
                        cout << "Element not found.\n";
                    }
                    flag = false;
                    system("pause");
                    break;
                }
                case 3:
                {
                    cout << "Enter a key to remove from the binary tree: ";
                    ValidateIntegerInput(key);
                    binaryTree.Remove(key);
                    break;
                }
                case 4:
                {
                    if (BinaryTreeNode* minNode = binaryTree.FindMin(binaryTree.GetNode()))
                    {
                        cout << "Minimum element in the binary tree: " << minNode->Data << "\n";
                    }
                    else
                    {
                        cout << "The tree is empty.\n";
                    }

                    flag = false;
                    system("pause");
                    break;
                }
                case 5:
                {
                    if (BinaryTreeNode* maxNode = binaryTree.FindMax(binaryTree.GetNode()))
                    {
                        cout << "Maximum element in the binary tree: " << maxNode->Data << "\n";
                    }
                    else
                    {
                        cout << "The tree is empty.\n";
                    }

                    flag = false;
                    system("pause");
                    break;
                }
                case 6:
                {
                    binaryTree.~BinaryTree();
                    cout << "Binary tree cleared.\n";
                    flag = false;
                    break;
                }
                case 0:
                {
                    system("cls");
                    flag = true;
                    break;
                }
                default:
                    system("cls");
                    break;
                }

            } while (subChoice != 0);
            break;

        case 2:
            do
            {
                system("cls");
                PrintTree(treap.GetNode());
                cout << "\n";
                PrintTreapMenu();
                cout << "Your choice: ";
                ValidateIntegerInput(subChoice);

                switch (subChoice)
                {
                case 1:
                {
                    cout << "Enter a key to add to the treap: ";
                    ValidateIntegerInput(key);
                    cout << "Enter a priority to add to the treap: ";
                    ValidateIntegerInput(priority);
                    treap.Insert(key, priority);
                    flag = false;
                    break;
                }
                case 2:
                {
                    cout << "Enter a key to find in the treap: ";
                    ValidateIntegerInput(key);
                    if (treap.Find(treap.GetNode(), key))
                    {
                        cout << "Element found.\n";
                    }
                    else
                    {
                        cout << "Element not found.\n";
                    }
                    flag = false;
                    system("pause");
                    break;
                }
                case 3:
                {
                    cout << "Enter a key to remove from the treap: ";
                    ValidateIntegerInput(key);
                    treap.Delete(key);
                    flag = false;
                    break;
                }
                case 4:
                {
                    treap.~Treap();
                    flag = false;
                    break;
                }
                case 0:
                {
                    system("cls");
                    flag = true;
                    break;
                }
                default:
                    system("cls");
                    break;
                }

            } while (subChoice != 0);
            break;

        case 0:
        {
            cout << "Exiting the program.\n";
            break;
        }
        default:
            system("cls");
            break;
        }
    } while (mainChoice != 0);

    return 0;
}
