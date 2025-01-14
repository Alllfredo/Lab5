#pragma once

//! \brief Структура для хранения узлов бинарного дерева.
struct BinaryTreeNode
{
    //! \brief Указатель на левый дочерний узел.
    BinaryTreeNode* Left;

    //! \brief Указатель на правый дочерний узел.
    BinaryTreeNode* Right;

    //! \brief Значение, хранимое в узле.
    int Data;

    //! \brief Конструктор, инициализирует узел с заданным значением.
    //! \param value Значение, которое нужно присвоить узлу.
    BinaryTreeNode(int value);

    //! \brief Деструктор. Освобождает память, выделенную для узла.
    ~BinaryTreeNode();
};
