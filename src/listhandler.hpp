#ifndef LISTHANDLER_HPP
#define LISTHANDLER_HPP

#include <QString>

class List;
class Armee;

class ListHandler
{
public:
    static void openList(QString file);

    static List* currentList();

    static void createList(const QString& nom, const Armee& armee);

private:
    List* m_currentList;

    ListHandler();

    static ListHandler& instance();
};

#endif // LISTHANDLER_HPP
