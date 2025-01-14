#pragma once
#include "..\\HeaderFiles\TreapNode.h"

class Treap
{
private:
    //! \brief Указатель на корень дерева.
    TreapNode* _node;

public:

    //! \brief Конструктор. Инициализирует пустое дерево.
    Treap();

    //! \brief Деструктор. Освобождает память, выделенную для дерева.
    ~Treap();

    //! \brief Геттер для получения корня дерева.
    //! \returns Указатель на корень дерева (_node).
    TreapNode* GetNode();

    //! \brief Разрезает дерево на две части по ключу.
    //! \param node Указатель на корень дерева.
    //! \param key Ключ, по которому нужно разрезать дерево.
    //! \param left Указатель на левую часть дерева после разреза.
    //! \param right Указатель на правую часть дерева после разреза.
    void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

    //! \brief Соединяет два дерева в одно.
    //! \param left Указатель на левое дерево.
    //! \param right Указатель на правое дерево.
    //! \returns Указатель на новое дерево, состоящее из левого и правого.
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    //! \brief Вставка элемента в декартово дерево.
    //! \param key Ключ элемента, который нужно вставить.
    //! \param priority Приоритет элемента, который нужно вставить.
    void Insert(int key, int priority);

    //! \brief Оптимизированная вставка без использования Merge().
    //! \param key Ключ элемента, который нужно вставить.
    //! \param priority Приоритет элемента, который нужно вставить.
    void OptimizedInsert(int key, int priority);

    //! \brief Удаление элемента с заданным ключом из декартова дерева.
    //! \param key Ключ элемента, который нужно удалить.
    void Delete(int key);

    //! \brief Оптимизированное удаление без использования Split.
    //! \param key Ключ элемента, который нужно удалить.
    void OptimizedDelete(int key);

    //! \brief Поиск узла с заданным ключом.
    //! \param node Указатель на текущий узел дерева.
    //! \param key Ключ, который нужно найти.
    //! \returns Указатель на узел с заданным ключом, если он найден, иначе nullptr.
    TreapNode* Find(TreapNode* node, int key);

    //! \brief Очистка памяти, выделенной для дерева.
    //! \param node Указатель на корень дерева, которое нужно очистить.
    void Clear(TreapNode* node);
};
