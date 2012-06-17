#include "listhandler.hpp"

void ListHandler::openList(QString file)
{

}

List* ListHandler::currentList()
{
    return instance().m_currentList;
}

void ListHandler::createList(const QString& nom, const Armee& armee)
{

}

ListHandler::ListHandler()
{
    m_currentList = 0;
}

ListHandler& ListHandler::instance()
{
    static ListHandler l;
    return l;
}
