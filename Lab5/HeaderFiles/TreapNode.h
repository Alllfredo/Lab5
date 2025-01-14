#pragma once

/// <summary>
/// Структура, представляющая узел декартового дерева (Treap).
/// </summary>
struct TreapNode
{
    //! \brief Ключ элемента в дереве.
    int Key;

    //! \brief Приоритет элемента в дереве.
    int Priority;

    //! \brief Указатель на левый дочерний узел.
    TreapNode* Left;

    //! \brief Указатель на правый дочерний узел.
    TreapNode* Right;

    //! \brief Конструктор узла.
    //! \param key Ключ элемента.
    //! \param priority Приоритет элемента.
    TreapNode(int key, int priority);

    //! \brief Деструктор узла. Освобождает память.
    ~TreapNode();
};
