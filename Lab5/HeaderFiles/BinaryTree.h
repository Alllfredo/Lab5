#pragma once
#include "..\\HeaderFiles\\BinaryTreeNode.h"

class BinaryTree
{
private:
    //! \brief Указатель на корень дерева.
    BinaryTreeNode* _node;

    //! \brief Рекурсивная функция удаления памяти дерева.
    //! \param node Указатель на узел, с которого начинается удаление.
    void FreeTree(BinaryTreeNode* node);

    //! \brief Рекурсивная функция для добавления элемента в дерево.
    //! \param node Указатель на текущий узел для добавления.
    //! \param value Значение, которое нужно добавить в дерево.
    void RecursiveAdd(BinaryTreeNode*& node, const int value);

    //! \brief Рекурсивная функция для удаления элемента из дерева.
    //! \param node Указатель на текущий узел для удаления.
    //! \param value Значение элемента, который нужно удалить.
    void RecursiveRemove(BinaryTreeNode*& node, const int value);

public:
    //! \brief Конструктор. Инициализирует пустое дерево.
    BinaryTree();

    //! \brief Деструктор. Очищает память, выделенную для дерева.
    ~BinaryTree();

    //! \brief Геттер для корневого элемента дерева.
    //! \returns Указатель на корень дерева.
    BinaryTreeNode* GetNode();

    //! \brief Поиск элемента в дереве.
    //! \param node Указатель на текущий узел для поиска.
    //! \param value Значение, которое нужно найти.
    //! \returns Указатель на найденный узел или nullptr, если элемент не найден.
    BinaryTreeNode* Find(BinaryTreeNode* node, int value);

    //! \brief Поиск минимального элемента в поддереве.
    //! \param node Указатель на корень поддерева для поиска минимального элемента.
    //! \returns Указатель на узел с минимальным значением.
    BinaryTreeNode* FindMin(BinaryTreeNode* node);

    //! \brief Поиск максимального элемента в поддереве.
    //! \param node Указатель на корень поддерева для поиска максимального элемента.
    //! \returns Указатель на узел с максимальным значением.
    BinaryTreeNode* FindMax(BinaryTreeNode* node);

    //! \brief Добавление элемента в дерево.
    //! \param value Значение, которое нужно добавить.
    void Add(int value);

    //! \brief Удаление элемента из дерева.
    //! \param value Значение, которого нужно удалить.
    void Remove(int value);
};
